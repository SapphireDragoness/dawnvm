#ifndef DVM_TYPES_H
#define DVM_TYPES_H

_Noreturn void dvm_log_unimplemented(const char *function, const char *file,
                                     const int line, const char *fmt, ...);

#define DVM_UNIMPL(...)                                                        \
  dvm_log_unimplemented(__func__, __FILE__, __LINE__, __VA_ARGS__)

#endif