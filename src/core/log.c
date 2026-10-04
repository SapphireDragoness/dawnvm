#include "dvm/types.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void dvm_log_info(const char *function, const char *file, const int line,
                  const char *fmt, ...) {
  va_list args;
  char msg[1024];

  va_start(args, fmt);
  vsnprintf(msg, 1024, fmt, args);
  va_end(args);

  fprintf(stderr, "[INFO] Function %s at %s:%d: %s\n", function, file, line,
          msg);
}