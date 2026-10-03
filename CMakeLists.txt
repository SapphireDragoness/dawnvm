cmake_minimum_required(VERSION 3.25)

project(DawnVM LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 REQUIRED CONFIG)
find_package(ZLIB REQUIRED)

add_executable(dawnvm)
add_library(dvm_core)

target_sources(dawnvm
    PRIVATE 
        src/main.c
)

target_sources(dvm_core
  PRIVATE       
    src/core/types.c
    src/core/jar.c
    src/core/classfile.c
    src/core/class.c
    src/core/heap.c
    src/core/interp.c
    src/core/thread.c
    src/core/native.c
    src/core/except.c
    src/jlib/lang.c
    src/jlib/util.c
    src/jlib/io.c
    src/midp/midlet.c
    src/midp/display.c
    src/midp/canvas.c
    src/midp/graphics.c
    src/midp/image.c
    src/midp/font.c
    src/midp/form.c
    src/midp/rms.c
    src/platform/sdl.c
    src/platform/config.c
    src/tools/overlay.c
    src/tools/savemgr.c
    src/tools/console.c

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
        include
)

target_link_libraries(dvm_core PUBLIC SDL3::SDL3)
target_link_libraries(dvm_core PUBLIC ZLIB::ZLIB)

target_link_libraries(dawnvm PRIVATE dvm_core)

option(DVM_SANITIZE "Passes -fsanitize=address,undefined and -fno-omit-frame-pointer to compiler and linker." OFF)
option(DVM_WERROR "Passes -Werror to compiler and linker." OFF)

target_compile_options(dvm_core PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wstrict-prototypes -Wmissing-prototypes -Wvla -Wimplicit-fallthrough $<$<BOOL:${DVM_SANITIZE}>:-fsanitize=address,undefined -fno-omit-frame-pointer> $<$<BOOL:${DVM_WERROR}>:-Werror>)
target_compile_options(dawnvm PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wstrict-prototypes -Wmissing-prototypes -Wvla -Wimplicit-fallthrough $<$<BOOL:${DVM_SANITIZE}>:-fsanitize=address,undefined -fno-omit-frame-pointer> $<$<BOOL:${DVM_WERROR}>:-Werror>)
target_link_options(dvm_core PRIVATE $<$<BOOL:${DVM_SANITIZE}>:-fsanitize=address,undefined -fno-omit-frame-pointer>)
target_link_options(dawnvm PRIVATE $<$<BOOL:${DVM_SANITIZE}>:-fsanitize=address,undefined -fno-omit-frame-pointer>)

# M5
# add_custom_command()

# M2
# add_test()