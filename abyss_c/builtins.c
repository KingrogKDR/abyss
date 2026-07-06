#include "builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cd_func(int argc, char **argv) {
  if (argc > 2) {
    fprintf(stderr, "cd: too many arguments\n");
    return 1;
  } else {
    const char *directory = (argc == 1) ? getenv("HOME") : argv[1];

    if (!directory) {
      fprintf(stderr, "cd: HOME not set\n");
      return 1;
    }

    if (chdir(directory) == -1) {
      perror("cd");
      return 1;
    }
  }
  return 0;
}

// TODO: make it more sophisticated with actual exit
int exit_func(int argc, char **argv) { exit(0); }

// TODO
int alias_func(int argc, char **argv) { return 0; }

int echo_func(int argc, char **argv) { return 0; }

int pwd_func(int argc, char **argv) { return 0; }