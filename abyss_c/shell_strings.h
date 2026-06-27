#ifndef SHELL_STRINGS_H
#define SHELL_STRINGS_H

#include "structs.h"

ShellString to_shellstr(char *cstring);
void print_shellstr(ShellString s);

#endif
