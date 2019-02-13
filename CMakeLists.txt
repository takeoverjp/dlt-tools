add_executable(dlt-diff dlt-diff.c)
target_link_libraries(dlt-diff dlt)

install(TARGETS dlt-diff
  RUNTIME
  DESTINATION bin)
