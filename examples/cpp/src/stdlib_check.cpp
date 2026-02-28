// Lint-clean source that includes C++ standard library headers.
// Exercises built-in include directory resolution: with -stdlib=libc++
// (from toolchains_llvm), clang-tidy must receive the platform system
// headers via cc_toolchain.built_in_include_directories passed as
// -idirafter flags.  On macOS, these are the Xcode SDK headers
// (wchar.h, stdlib.h, math.h) that libc++ depends on.
// See: https://github.com/aspect-build/rules_lint/issues/566
#include <string>

namespace {
std::string greet(const std::string& name) {
    return "Hello, " + name + "!";
}
}  // namespace
