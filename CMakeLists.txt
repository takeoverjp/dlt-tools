add_executable(dlt-diff diff.c)
target_link_libraries(dlt-diff dlt)

install(TARGETS dlt-diff
  RUNTIME
  DESTINATION bin)
