DEFAULT_TEST_NAME := "init"

alias t := test

test name=DEFAULT_TEST_NAME:
    clang src/test.c -o tests/{{name}}
    ./tests/{{name}}
