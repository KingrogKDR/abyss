#include "customs.h"
#include "shell_strings.h"
#include <stdlib.h>
#include <unistd.h>

ShellString read_input() {
  ShellString prompt = to_shellstr("abyss > ");
  print_shellstr(prompt);

  char *buf = malloc(1024);

  ssize_t n = read(STDIN_FILENO, buf, 1023);
  if (n <= 0) {
    free(buf);
    buf = NULL;
    return (ShellString){0};
  }

  return (ShellString){
      .data = buf,
      .len = n,
  };
}