#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <dlt/dlt.h>

#define BUFSIZE (256 * 1024)

static u_char is_verbose = 0;

static void
dlt2txt (const char * const path)
{
  DltFile file;
  char buf[BUFSIZE];
  DltReturnValue ret;

  ret = dlt_file_init (&file, is_verbose);
  assert (ret >= DLT_RETURN_OK);

  ret = dlt_file_open (&file, path, is_verbose);
  assert (ret >= DLT_RETURN_OK);

  do
    {
      ret = dlt_file_read (&file, is_verbose);
    }
  while (ret >= DLT_RETURN_OK);

  for (int i = 0; i < file.counter; i++)
    {
      dlt_file_message (&file, i, is_verbose);
      printf ("%d ", i);
      dlt_message_header (&file.msg, buf, sizeof(buf), is_verbose);
      printf ("%s ", buf);
      dlt_message_payload (&file.msg, buf, sizeof(buf),
                          DLT_OUTPUT_ASCII, is_verbose);
      printf("[%s]\n", buf);
    }

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
  assert (access (path, R_OK) == 0);

  dlt2txt (path);

  return 0;
}
