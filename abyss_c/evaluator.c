#include "evaluator.h"
#include "builtins.h"
#include "command.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 64

static const command_t builtin_commands[] = {
    {.name = "cd", .execute = cd_func},
    {.name = "exit", .execute = exit_func},
    {.name = "alias", .execute = alias_func},
    {.name = "echo", .execute = echo_func},
    {.name = "pwd", .execute = pwd_func},
};

// Todo: implement a custom tokenizer and parser later
int split_input(char *s, char **argv) {
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

const command_t *search_builtins(const char *exe) {
  size_t builtin_len = sizeof(builtin_commands) / sizeof(builtin_commands[0]);
  for (size_t i = 0; i < builtin_len; i++) {
    int res = strcmp(builtin_commands[i].name, exe);
    if (res == 0) {
      return &builtin_commands[i];
    }
  }
  return NULL;
}

int external_execute(int argc, char **argv) {
  pid_t pid = fork();

  if (pid == 0) {
    execvp(argv[0], argv);
    perror(argv[0]);
    _exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("fork");
    return 1;
  }

  int status;
  waitpid(pid, &status, 0);

  return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}

void eval_command(char *cmd_input) {
  char *argv[MAX_ARGS + 1]; // because we store an extra null
  int argc = split_input(cmd_input, argv);

  if (argc <= 0) {
    return;
  }
  const command_t *cmd = search_builtins(argv[0]);
  int status;
  if (cmd) {
    status = cmd->execute(argc, argv);
  } else {
    status = external_execute(argc, argv);
  }
}