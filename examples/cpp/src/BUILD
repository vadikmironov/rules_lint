load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "hello_cc",
    srcs = ["hello.cpp"],
)

cc_library(
    name = "stdlib_check",
    srcs = ["stdlib_check.cpp"],
    # -stdlib=libc++ selects the libc++ standard library implementation,
    # matching the toolchains_llvm configuration from issue #566.
    # On macOS, the Xcode SDK platform headers (wchar.h, stdlib.h, math.h)
    # are only available via cc_toolchain.built_in_include_directories;
    # without the -idirafter fix, clang-tidy cannot resolve them and fails.
    copts = ["-stdlib=libc++"],
)

filegroup(
    name = "all",
    srcs = [
        "hello.cu",
        ":hello_cc",
        "//src/cpp/main:hello-world",
    ],
)
