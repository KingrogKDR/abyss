#include "defer.h"

void defer_push(DeferStack *s, DeferFn fn, void *arg) {
  s->stack[s->len++] = (Deferred){
      .fn = fn,
      .arg = arg,
  };
}