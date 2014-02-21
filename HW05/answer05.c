#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <libgen.h>

#include "answer05.h"

#define TRUE 1
#define FALSE 0
#define BITS_PER_PIXEL 8

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
          //Read header
          read = fread(&header, sizeof(ImageHeader), 1, file);
	  
	  if (read != 1) { //Header read failure
	       fprintf(stderr, "Failed to read header from '%s'\n", filename);
	       error = TRUE;
	  } 
     }

     if (!error) { //print out header info
          printf("Printing EE264 header information:\n");
	  printf("  file type (should be %x): %x\n", ECE264_IMAGE_MAGIC_NUMBER, header.magic_number);
	  printf("  file width: %d\n", header.width);
	  printf("  file height: %d\n", header.height);
	  printf("  file comment size: %d\n", header.comment_len);
     }

     if (!error) { //check file validity
          if (header.magic_number != ECE264_IMAGE_MAGIC_NUMBER) {
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
	  char * filenameCopy = strdup(filename);
	  char * file_basename = basename(filenameCopy);
	  const char * prefix = "Original ee264 file: ";
	  
	  n_bytes = sizeof(char) * (strlen(prefix) + strlen(file_basename) + 1);
	  ImageTemp->comment = malloc(n_bytes);
	  
	  if (ImageTemp->comment == NULL) { //there is no comment area
	       fprintf(stderr, "Failed to allocate %zd bytes for comment\n", n_bytes);
	       error = TRUE;
	  } else {
	       sprintf(ImageTemp->comment, "%s%s", prefix, file_basename);
	  }
	 
	  free(filenameCopy); //the free of strdup's malloc

	  //Handle image data
	  n_bytes = (sizeof(uint8_t) * header.width * header.height);
	  ImageTemp->data = malloc(n_bytes);

	  if (ImageTemp->data == NULL) {
	       //No image data space
	       fprintf(stderr, "Failed to allocate %zd bytes for image data\n", n_bytes); 
	       error = TRUE;
	  } 
	  //	  free(ImageTemp->comment);
     }

     /* if (!error) { //Seek start of pixel data
       if (fseek(file, 
     }
     */

     if (!error) { //Read pixel data
          size_t bytes_per_row = ((BITS_PER_PIXEL * header.width + 31) / 32) * 4;
	  n_bytes = bytes_per_row * header.height;
	  uint8_t * rawEE264 = malloc(n_bytes);

	  if (rawEE264 == NULL) { //Image byte data not allocated
  	       fprintf(stderr, "Could not allocate %zd bytes of image data\n", n_bytes);
	       error = TRUE;
	  } else { //Image byte data allocation attempted
	       read = fread(rawEE264, sizeof(uint8_t), n_bytes, file);

	       if (n_bytes != read) {//Not reading entire data chunk
		    fprintf(stderr, "Only read %zd of %zd bytes of image data\n", read, n_bytes);
		    error = TRUE;
	       } else {//convert to Grayscale
		    uint8_t * write_ptr = ImageTemp->data;
		    uint8_t * read_ptr;
		    int intensity;
		    int row;
		    int column;

		    for (row = 0; row < header.height; ++row) {
		         read_ptr = &rawEE264[row * bytes_per_row];
			 
			 for (column = 0; column < header.width; ++column) {
			      intensity = *read_ptr++;  //blue
			      intensity += *read_ptr++; //green
			      intensity += *read_ptr++; //red
			      *write_ptr++ = intensity / 3; //now grayscale
			 }
		    }
	       }
	  }
	  free(rawEE264);
     }

     if (!error) { //Set up data return
          ImageMain = ImageTemp; //EE264 image will be returned
	  ImageTemp = NULL; //and not cleaned up
     }

     if (ImageTemp != NULL) { //clean up
          free(ImageTemp->comment);
	  free(ImageTemp->data);
	  free(ImageTemp);
     }

     if (file) { //file stream still open
          fclose(file);
     }

     if (error) { // NULL on error, image data on success
          return(NULL);
     } else {
          return(ImageMain);
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
     if (image != NULL) {
          free(image->comment);
          free(image->data);
          free(image);
     }
}

/**
 * Performs linear normalization, see README
 */
void linearNormalization(int width, int height, uint8_t * intensity) {
     uint8_t maxIntensity = 0;
     uint8_t minIntensity = 255;
     int curPixel;
     int n_pixels = width * height;

     for (curPixel = 0; curPixel < n_pixels; curPixel++) {
          if (intensity[curPixel] < minIntensity) {
	       minIntensity = intensity[curPixel];
	  }
	  if (intensity[curPixel] > maxIntensity) {
	       maxIntensity = intensity[curPixel];
	  }
     }

     for (curPixel = 0; curPixel < n_pixels; curPixel++) {
          intensity[curPixel] = (intensity[curPixel] - minIntensity) * 255.0 / (maxIntensity - minIntensity);
     }
}
