#ifndef DEFER_H
#define DEFER_H

#include <stddef.h>

/* A function pointer to a function that acts like the defer function in Go */
typedef void *(*DeferFn)(void *);

/* A deferred function */
typedef struct {
  DeferFn fn;
  void *arg;
} Deferred;

/* a stack to ensure defer functions maintain LIFO order. Can only contain upto
 * 32 deferred functions */
typedef struct {
  Deferred stack[32];
  size_t len;
} DeferStack;

#define defer(stack, fn, arg) defer_push((&stack), (DeferFn)(fn), (arg))

void defer_push(DeferStack *s, DeferFn fn, void *arg);

#endif