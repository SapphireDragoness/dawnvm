#include "dvm/types.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((format(printf, 4, 5))) _Noreturn void
dvm_log_unimplemented(const char *function, const char *file, const int line,
                      const char *fmt, ...) {
  va_list args;
  char msg[1024];

  va_start(args, fmt);
  vsnprintf(msg, 1024, fmt, args);
  va_end(args);

  fprintf(stderr, "UNIMPLEMENTED: function %s at %s:%d: %s\n", function, file,
          line, msg);

  abort();
}