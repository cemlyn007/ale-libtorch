#include "ai/environment/episode_recorder.h"

namespace ai::environment {

EpisodeRecorder::EpisodeRecorder(std::unique_ptr<VirtualEnvironment> env,
                                 const std::filesystem::path &video_path)
    : episode_index_(0), env_(std::move(env)), screen_buffer_(),
      video_recorder_([&]() {
        auto screen = env_->get_interface().getScreen();
        return ai::video_recorder::VideoRecorder(video_path, 1, screen.width(),
                                                 screen.height(), 30);
      }()) {
  screen_buffer_.resize(env_->get_interface().getScreen().height() *
                        env_->get_interface().getScreen().width());
}

void EpisodeRecorder::reset() {
  env_->reset();
  episode_index_++;
  env_->get_interface().getScreenGrayscale(screen_buffer_);
  video_recorder_.add(screen_buffer_.data());
}

Step EpisodeRecorder::step(const ale::Action &action) {
  auto result = env_->step(action);
  env_->get_interface().getScreenGrayscale(screen_buffer_);
  video_recorder_.add(screen_buffer_.data());
  if (result.terminated || result.truncated) {
    std::filesystem::path path =
        "episode_" + std::to_string(episode_index_) + ".mp4";
    video_recorder_.complete(path);
  }
  return result;
}

ale::ALEInterface &EpisodeRecorder::get_interface() {
  return env_->get_interface();
}

} // namespace ai::environment
