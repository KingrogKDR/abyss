#ifndef COMMAND_H
#define COMMAND_H

typedef int (*executor_fn)(int argc, char **argv);

typedef struct {
  const char *name;
  executor_fn execute;
} command_t;

#endif