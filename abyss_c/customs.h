#ifndef CUSTOMS_H
#define CUSTOMS_H

#include <stddef.h>

/* A custom string that is size-aware */
typedef struct {
  char *data;
  size_t len;
} ShellString;

/* Function pointer for the evaluator.
 * Takes the reader input and returns the evaluated result.
 */
typedef char *(*EvalFn)(const char *input);

typedef struct {
  EvalFn eval;
} Evaluator;

typedef struct {
  char *output;
} Writer;

#endif