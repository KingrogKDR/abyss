#include "customs.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 64

// Todo: implement a custom tokenizer later
int split_input(ShellString s, char **argv) {
  if (!s.data) {
    return 0;
  }

  int argc = 0;
  char *token = strtok(s.data, " ");

  while (token != NULL) {
    if (argc >= MAX_ARGS) {
      fprintf(stderr, "too many arguments: maximum argument size is %d\n",
              MAX_ARGS);
      return -1;
    }
    argv[argc++] = token;
    token = strtok(NULL, " ");
  }

  argv[argc] = NULL; // execvp needs this to determine the argv length
  return argc;
}

void is_valid_command(const char *first_word) {}

void eval_command(ShellString s) {
  char *argv[MAX_ARGS + 1]; // because we store an extra null
  int argc = split_input(s, argv);

  if (argc <= 0) {
    return;
  }
}