# Copyright (c) 2024 Frank Vanbever
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
# the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

add_custom_target(gen-version-h
  COMMAND "${CMAKE_COMMAND}"
  "-D" "SRC_DIR=${PROJECT_SOURCE_DIR}/src"
  "-D" "BIN_DIR=${CMAKE_CURRENT_BINARY_DIR}"
  "-P" "${PROJECT_SOURCE_DIR}/support/version.cmake"
  COMMENT "Generating git version file"
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
file(GLOB SOURCES "*.c")
add_executable(demo ${SOURCES})

add_dependencies(demo gen-version-h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
