#pragma once
#include "ai/environment/environment.h"
#include "ai/video_recorder.h"
#include <memory>

namespace ai::environment {

class EpisodeRecorder : public VirtualEnvironment {
public:
  explicit EpisodeRecorder(std::unique_ptr<VirtualEnvironment> env,
                           const std::filesystem::path &video_path,
                           bool grayscale);
  ScreenBuffer reset() override;
  Step step(const ale::Action &action) override;
  ale::ALEInterface &get_interface() override;

private:
  size_t episode_index_;
  std::unique_ptr<VirtualEnvironment> env_;
  ai::video_recorder::VideoRecorder video_recorder_;
};

} // namespace ai::environment
