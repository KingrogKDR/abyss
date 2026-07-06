#ifndef BUILTINS_H
#define BUILTINS_H

#include "custom.h"

int cd_func(Shell *, int, char **);
int exit_func(Shell *, int, char **);
int alias_func(Shell *, int, char **);
int echo_func(Shell *, int, char **);
int pwd_func(Shell *, int, char **);

#endif