package(default_visibility = ["//visibility:public"])

cc_library(
    name = "environment",
    srcs = [
        "environment.cc",
    ],
    hdrs = [
        "environment.h",
    ],
    strip_include_prefix = "/src",
    deps = [
        "@arcade_learning_environment//:ale",
    ],
)

cc_library(
    name = "episode_life",
    srcs = [
        "episode_life.cc",
    ],
    hdrs = [
        "episode_life.h",
    ],
    strip_include_prefix = "/src",
    deps = [
        ":environment",
        "@arcade_learning_environment//:ale",
    ],
)

cc_library(
    name = "episode_recorder",
    srcs = [
        "episode_recorder.cc",
    ],
    hdrs = [
        "episode_recorder.h",
    ],
    strip_include_prefix = "/src",
    deps = [
        ":environment",
        "//src/ai:video_recorder",
        "@arcade_learning_environment//:ale",
    ],
)
