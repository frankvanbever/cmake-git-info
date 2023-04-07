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
