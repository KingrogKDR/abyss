#ifndef STRUCTS_H
#define STRUCTS_H

#include <stddef.h>

/* A custom string that is size-aware */
typedef struct ShellString {
  char *data;
  size_t len;
} ShellString;

// typedef struct Reader {
//   char *input;
// } Reader;

/* Function pointer for the evaluator.
 * Takes the reader input and returns the evaluated result.
 */
typedef char *(*EvalFn)(const char *input);

typedef struct Evaluator {
  EvalFn eval;
} Evaluator;

typedef struct Writer {
  char *output;
} Writer;

#endif