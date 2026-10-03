#include "dvm/types.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct option Option;

int main(int argc, char *argv[]) {
  int c;

  static Option long_options[] = {{"help", no_argument, NULL, 'h'},
                                  {NULL, 0, NULL, 0}};
  int option_index = 0;
  while ((c = getopt_long(argc, argv, "h", long_options, &option_index)) !=
         -1) {
    switch (c) {
    case 'h':
      fprintf(stdout, "Usage: %s --help\n", argv[0]);
      break;
    default:
      fprintf(stderr, "Usage: %s --help\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }
  if (argc == 1) {
    fprintf(stderr, "Usage: %s --help\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}