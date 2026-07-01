#include "evaluator.h"
#include "builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_ARGS 64

static const char *builtin_commands[] = {"cd", "exit", "alias", "echo", "pwd"};

int compare_strs(const char *s, const char *t) { return strcmp(s, t); }

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
    int res = compare_strs(ev->built_ins[i], cmd);
    if (res == 0) {
      return i;
    }
  }
  return -1;
}

void execute_builtin(int argc, const char **argv) {
  const char *cmd = argv[0];
  if (compare_strs(cmd, "cd") == 0) {
    cd_func(argc, argv);
  } else if (compare_strs(cmd, "exit") == 0) {
    exit_func();
  } else if (compare_strs(cmd, "alias") == 0) {
    alias_func(argc, argv);
  } else if (compare_strs(cmd, "echo") == 0) {
    echo_func(argc, argv);
  } else if (compare_strs(cmd, "pwd") == 0) {
    pwd_func();
  }
}

void eval_command(Evaluator *ev, char *cmd_input) {
  const char *argv[MAX_ARGS + 1]; // because we store an extra null
  int argc = split_input(cmd_input, argv);

  if (argc <= 0) {
    return;
  }

  int searchRes = search_builtins(ev, argv[0]);
  if (searchRes == -1) {
    // external command
    // check if it exists
    // if yes
    // fork
    // search for the executable using execvp
  } else {
    execute_builtin(argc, argv);
  }
}