#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#include "answer05.h"

int main (int argc, char ** argv) {
  int ret = EXIT_SUCCESS;

  const char * in_filename = argv[1];
  const char * out_filename = argv[2];

  Image * im = Image_loadbmp(in_filename);
  Image_save(out_filename, im);

  Image_free(im);

  return(ret);



}
