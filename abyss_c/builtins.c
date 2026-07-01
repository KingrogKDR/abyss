#include "builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cd_func(int argc, const char **argv) {
  if (argc > 2) {
    perror("cd: too many arguments");
    return;
  } else {
    const char *directory;
    if (argc == 1) {
      directory = getenv("HOME");
      if (!directory) {
        perror("failed getting home env");
        return;
      }
    } else {
      directory = argv[1];
    }
    int res = chdir(directory);
    if (res == -1) {
      perror("failed changing directory");
      return;
    }
  }
}

void exit_func(void) { exit(0); }

void alias_func(int argc, const char **argv) {}

void echo_func(int argc, const char **argv) {}

void pwd_func() {}