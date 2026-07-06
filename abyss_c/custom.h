#ifndef CUSTOM_H
#define CUSTOM_H

/* global shell state */
typedef struct {
  int last_exit_status;
} Shell;

typedef int (*executor_fn)(Shell *shell, int argc, char **argv);

typedef struct {
  const char *name;
  executor_fn execute;
} command_t;

#endif