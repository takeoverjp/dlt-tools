#include <stdio.h>
#include <stdlib.h>

#include <dlt/dlt.h>

static u_char is_verbose = 1;

static void
dlt_diff (char *fpath1, char *fpath2)
{
  DltFile file1, file2;

  dlt_file_init (&file1, is_verbose);
  dlt_file_init (&file2, is_verbose);
  dlt_file_free (&file2, is_verbose);
  dlt_file_free (&file1, is_verbose);
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "[USAGE] %s DLT1 DLT2\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  printf ("Compare %s %s\n", argv[1], argv[2]);

  dlt_diff (argv[1], argv[2]);

  return 0;
}
