#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <libgen.h>

#include "answer05.h"

#define TRUE 1
#define FALSE 0

/*
typedef struct ImageHeader_st {
  uint32_t magic_number; // Should be ECE264_IMAGE_MAGIC_NUMBER
  uint32_t width;        // [width x height], cannot be zero
  uint32_t height;
  uint32_t comment_len; // A comment embedded in the file
} ImageHeader;
typedef struct Image_st {
  int width;
  int height;
  char * comment;
  uint8_t * data;
} Image;
*/

/**
 * Loads an ECE264 image file, returning an Image structure.
 * Will return NULL if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
Image * Image_load(const char * filename) {
     FILE * file = NULL;
     size_t read;
     ImageHeader header;
     Image * ImageTemp = NULL;
     Image * ImageMain = NULL;
     size_t n_bytes = 0;
     int error = FALSE;

     if (!error) { //Try to open image file stream
          file = fopen(filename, "rb"); //Open file with non-text read
	  
	  if (!file) { //File is null
	       fprintf(stderr, "Failed to open file '%s'\n", filename);
	       error = TRUE;
	  }
     }

     if (!error) { //Try to read image header
          read = fread(&header, sizeof(EE264_Header), 1, file); //Read header
	  
	  if (read != 1) { //Header read failure
	       fprintf(stderr, "Failed to read header from '%s'\n", filename);
	       error = TRUE;
	  } 
     }

     if (!error) { //print out header info
          printf("Printing EE264 header information:\n");
	  printf("  file type (should be %x): %x\n", EE264_MAGIC_NUM, header.type);
	  printf("  file width: %d\n", header.width);
	  printf("  file height: %d\n", header.height);
	  printf("  file comment size: %d\n", header.com_l);
     }

     if (!error) { //check file validity
          if (header.type != EE264_MAGIC_NUM) {
	       fprintf(stderr, "Invalid header in '%s'\n", filename);
	       error = TRUE;
	  }
     }

     if (!error) {//Allocate Image struct
          ImageTemp = malloc(sizeof(Image));
	  
	  if (ImageTemp == NULL) {
	       fprintf(stderr, "Failed to allocate image structure.\n");
	       error = TRUE;
	  }
     }
     
     if (!error) { //Initialize the image struct
          ImageTemp->width = header.width;
	  ImageTemp->height = header.height;

	  //find the comment in the header
	  char * filename2 = strdup(filename);
	  char * file_basename = basename(filename2);
	  const char * prefix = "Original ee264 file: ";
	  
	  n_bytes = sizeof(char) * (strlen(prefix) + strlen(file_basename) + 1);
	  ImageTemp->comment = malloc(n_bytes);


	  free(ImageTemp->comment);
	  
	  


     }

     if (error) { // NULL on error, 0 on success
          return(NULL);
     } else {
          return(EXIT_SUCCESS);
     }
}

/**
 * Save an image to the passed filename, in ECE264 format.
 * Return TRUE if this succeeds, or FALSE if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
int Image_save(const char * filename, Image * image) {
  


     return(0);
}

/**
 * Free memory for an image structure
 *
 * Image_load(...) (above) allocates memory for an image structure. 
 * This function must clean up any allocated resources. If image is 
 * NULL, then it does nothing. (There should be no error message.) If 
 * you do not write this function correctly, then valgrind will 
 * report an error. 
 */
void Image_free(Image * image) {


}

/**
 * Performs linear normalization, see README
 */
void linearNormalization(int width, int height, uint8_t * intensity) {


}



//int main (int argc, char ** argv) {

//return(0);
//}
