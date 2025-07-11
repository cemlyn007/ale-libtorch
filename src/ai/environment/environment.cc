#include "ai/environment/environment.h"

namespace ai::environment {

Environment::Environment(const std::filesystem::path &rom_path,
                         size_t max_num_frames_per_episode, size_t frame_skip,
                         float repeat_action_probability, int seed)
    : ale_() {
  if (rom_path.empty()) {
    throw std::invalid_argument("ROM path must not be empty.");
  }
  if (!std::filesystem::exists(rom_path)) {
    throw std::invalid_argument("ROM file does not exist: " +
                                rom_path.string());
  }
  ale_.setInt("max_num_frames_per_episode",
              static_cast<int>(max_num_frames_per_episode));
  ale_.setInt("frame_skip", static_cast<int>(frame_skip));
  ale_.setFloat("repeat_action_probability", repeat_action_probability);
  ale_.setInt("random_seed", seed);
  ale_.setInt("max_num_frames_per_episode", 0);
  ale_.loadROM(rom_path.string());
}

void Environment::reset() { ale_.reset_game(); }

Step Environment::step(const ale::Action &action) {
  Step result;
  result.reward = ale_.act(action);
  result.terminated = ale_.game_over(false);
  result.truncated = ale_.game_truncated();
  return result;
}

ale::ALEInterface &Environment::get_interface() { return ale_; }

} // namespace ai::environment
