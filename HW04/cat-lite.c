#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
     FILE *file;
     char file_name[255];
     char ch;
     int counter = 0;

     if (argc < 1) {
          printf("Usage: ./cat-lite <filename>\n");
	  return(EXIT_SUCCESS);
     }

     for (counter = 1; counter < argc; counter++) {
          strncpy(file_name, argv[counter], 255);  

	  file = fopen(file_name, "r");
     
	  if (file == NULL) {
	       printf("Cannot find file: %s\n", file_name);
	       return(EXIT_SUCCESS);
	  }

	  while((ch == fgetc(file)) != EOF) {
	       putchar(ch);
	  }

	  fclose(file);
     }       
     return(EXIT_SUCCESS);
}
