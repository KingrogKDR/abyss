#include "structs.h"
#include <string.h>
#include <unistd.h>

ShellString to_shellstr(char *cstring) {
  return (ShellString){
      .data = cstring,
      .len = strlen(cstring),
  };
}

void print_shellstr(ShellString s) { write(STDOUT_FILENO, s.data, s.len); }
