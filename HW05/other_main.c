#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#include "answer05.h"

int main (int argc, char ** argv) {
     int ret = EXIT_SUCCESS;
     
     const char * in_filename = argv[1];
     const char * out_filename = argv[2];

     Image * im = Image_load(in_filename);
     if (im == NULL) {
          fprintf(stderr, "Error: failed to read '%s'\n", in_filename);
	  return(EXIT_FAILURE);
     }



     if (!Image_save(out_filename, im)) {
          fprintf(stderr, "Error: attempting to write '%s'\n", out_filename);
	  ret = EXIT_FAILURE;
     }

     Image_free(im);

     return(ret);
}
