DEFAULT_TEST_SUITE := "all"
DEFAULT_DEBUG_PROFILE := "-O0 -D_DEBUG"
DEFAULT_COMPILED_TESTS_PATH := "tests/bin"

alias t := test

[private]
default:
    just --list

prepare:
    mkdir -p tests/bin

[arg("profile", long="release", short="r", value="-O2")]
[arg("asan", long="asan", value="-fsanitize=address")]
[arg("msan", long="msan", value="-fsanitize=memory")]
[arg("tsan", long="tsan", value="-fsanitize=thread")]
[arg("valgrind", long="valgrind", value="valgrind")]
test name profile=DEFAULT_DEBUG_PROFILE asan="" msan="" tsan="" valgrind="":
    clang tests/{{name}}.c -Wall {{profile}} {{asan}} {{msan}} {{tsan}} -o {{DEFAULT_COMPILED_TESTS_PATH}}/{{file_stem(name)}}
    {{valgrind}} ./tests/bin/{{name}}
