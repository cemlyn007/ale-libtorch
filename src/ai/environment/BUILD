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

cc_library(
    name = "fire_reset",
    srcs = [
        "fire_reset.cc",
    ],
    hdrs = [
        "fire_reset.h",
    ],
    strip_include_prefix = "/src",
    deps = [
        ":environment",
    ],
)

cc_library(
    name = "max_and_skip",
    srcs = [
        "max_and_skip.cc",
    ],
    hdrs = [
        "max_and_skip.h",
    ],
    strip_include_prefix = "/src",
    deps = [
        ":environment",
    ],
)

cc_library(
    name = "noop_reset",
    srcs = [
        "noop_reset.cc",
    ],
    hdrs = [
        "noop_reset.h",
    ],
    strip_include_prefix = "/src",
    deps = [
        ":environment",
    ],
)

cc_library(
    name = "reset_on_return",
    srcs = [
        "reset_on_return.cc",
    ],
    hdrs = [
        "reset_on_return.h",
    ],
    strip_include_prefix = "/src",
    deps = [
        ":environment",
        "@arcade_learning_environment//:ale",
    ],
)
