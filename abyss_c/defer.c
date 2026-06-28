#include "defer.h"

void defer_push(DeferStack *s, DeferFn fn, void *arg) {
  s->stack[s->len++] = (Deferred){
      .fn = fn,
      .arg = arg,
  };
}

void defer_run(DeferStack *s) {
  while (s->len) {
    Deferred d = s->stack[--s->len];
    d.fn(d.arg);
  }
}