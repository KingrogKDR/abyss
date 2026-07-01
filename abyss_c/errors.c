#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exit_with_success(char *msg) {
  write(STDOUT_FILENO, msg, strlen(msg));
  exit(0);
}

void exit_with_failure(char *msg) {
  perror(msg);
  exit(-1);
}
