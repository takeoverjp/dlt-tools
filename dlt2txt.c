#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dlt/dlt.h>

static u_char is_verbose = 0;

static void
dlt2txt (const char * const path)
{
  DltFile file;

  dlt_file_init (&file, is_verbose);
  dlt_file_free (&file, is_verbose);
}

static void
usage (void)
{
  fprintf (stderr, "[USAGE] dlt2txt DLT\n");
  exit (EXIT_FAILURE);
}

int
main (int argc, char *argv[])
{
  int c = -1;

  while ((c = getopt (argc, argv, "hv")) != -1)
    {
      switch (c)
        {
        case 'v':
          is_verbose = 1;
          break;
        case 'h':
        default:
          usage ();
          break;
        }
    }

  if (argc - optind != 1)
    {
      usage ();
    }

  const char *path = argv[optind];

  dlt2txt (path);

  return 0;
}
