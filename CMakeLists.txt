cmake_minimum_required(VERSION 3.5)
add_executable(dlt2txt dlt2txt.c)
target_link_libraries(dlt2txt dlt)
add_executable(dlt-diff dlt-diff.c)
target_link_libraries(dlt-diff dlt)

install(TARGETS dlt2txt dlt-diff
  RUNTIME
  DESTINATION bin)

enable_testing()
add_subdirectory(tests)
