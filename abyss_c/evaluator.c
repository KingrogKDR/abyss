#include "evaluator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 64

static const char *builtin_commands[] = {"cd", "exit", "alias", "echo"};

Evaluator *eval_init(void) {
  Evaluator *ev = calloc(1, sizeof(Evaluator));
  if (!ev) {
    return NULL;
  }
  ev->built_ins = builtin_commands;
  ev->builtin_len = sizeof(builtin_commands) / sizeof(builtin_commands[0]);
  return ev;
}

// Todo: implement a custom tokenizer and parser later
int split_input(char *s, const char **argv) {
  if (!s) {
    return 0;
  }

  int argc = 0;
  char *token = strtok(s, " ");

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

int search_builtins(Evaluator *ev, const char *cmd) {
  for (int i = 0; i < ev->builtin_len; i++) {
    int res = strcmp(ev->built_ins[i], cmd);
    if (res == 0) {
      return i;
    }
  }
  return -1;
}

void execute_builtin(int argc, const char **argv) { const char *cmd = argv[0]; }

void eval_command(Evaluator *ev, char *cmd_input) {
  const char *argv[MAX_ARGS + 1]; // because we store an extra null
  int argc = split_input(cmd_input, argv);

  if (argc <= 0) {
    return;
  }

  int searchRes = search_builtins(ev, argv[0]);
  if (searchRes == -1) {
    // fork
    // search for the executable using execvp
  } else {
    execute_builtin(argc, argv);
  }
}