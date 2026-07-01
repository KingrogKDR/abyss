#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <stddef.h>

typedef struct Evaluator {
  const char **built_ins;
  size_t builtin_len;
} Evaluator;

Evaluator *eval_init(void);

void eval_command(Evaluator *, char *);

#endif