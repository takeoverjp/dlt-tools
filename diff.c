#include <stdio.h>
#include <stdlib.h>

#include <dlt/dlt.h>


int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "[USAGE] %s DLT1 DLT2\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  printf ("Compare %s %s\n", argv[1], argv[2]);

  return 0;
}
