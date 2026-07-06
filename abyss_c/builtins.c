#include "custom.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cd_func(Shell *shell, int argc, char **argv) {
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

int is_valid_exit_input(const char *arg) {
  char *end;
  errno = 0;
  long status = strtol(arg, &end, 10);
  if (end == arg || *end != '\0' || errno == ERANGE) {
    fprintf(stderr, "exit: numeric argument required\n");
    exit(2);
  }
  return (status & 0xFF);
}

int exit_func(Shell *shell, int argc, char **argv) {
  if (argc == 1) {
    exit(shell->last_exit_status);
  }

  int status = is_valid_exit_input(argv[1]);

  if (argc > 2) {
    fprintf(stderr, "exit: too many arguments\n");
    return 1;
  }

  exit(status);
}

// TODO
int alias_func(Shell *shell, int argc, char **argv) { return 0; }

int echo_func(Shell *shell, int argc, char **argv) { return 0; }

int pwd_func(Shell *shell, int argc, char **argv) { return 0; }