#include "reader.h"
#include "structs.h"
#include <stdlib.h>
#include <unistd.h>
// REPL (read eval print loop)

// Data stuctures
// Reader -  take user input and return it if it is relevant to the list of
// commands included
// Evaluator - takes the user input, evaluates it, and returns
// the result and passes the some output to be printed to the writer if any
// Writer - takes the output from the evaluator and prints it to the screen

// This entire process will loop until user inputs a certain command / keyboard
// shortcut or shutdown signal

// Optimizations:
// - minimize memory usage
// - capable of multiple concurrent commands without slowing down or consuming
// too much memory

int main() {
  while (1) {
    ShellString input = read_input();
    write(STDOUT_FILENO, "You typed: ", 11);
    write(STDOUT_FILENO, input.data, input.len);
    free(input.data);
    input.data = NULL;
  }
  return 0;
}
