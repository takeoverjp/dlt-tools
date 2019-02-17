#include <stdio.h>
#include <stdlib.h>
#include <dlt/dlt.h>

DLT_DECLARE_CONTEXT(con_exa1);

int
main (void)
{
  DLT_REGISTER_APP("EXA1", "First Example");
  DLT_REGISTER_CONTEXT(con_exa1, "CON", "First context");
  for (int i = 0; i < 10; i++)
    DLT_LOG(con_exa1, DLT_LOG_INFO, DLT_STRING("Hello world!"), DLT_INT32(i));
  usleep(1000);
  DLT_UNREGISTER_CONTEXT(con_exa1);
  DLT_UNREGISTER_APP();
}
