#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *read_input() {
  char *prompt = "abyss > ";
  write(STDOUT_FILENO, prompt, strlen(prompt));

  char *buf = malloc(1024);
  if (!buf) {
    fprintf(stderr, "failed creating buffer");
  }

  ssize_t n = read(STDIN_FILENO, buf, 1023);
  if (n <= 0) {
    free(buf);
    return "";
  }
  if (buf[n - 1] == '\n') {
    buf[--n] = '\0';
  } else {
    buf[n] = '\0';
  }

  return buf;
}