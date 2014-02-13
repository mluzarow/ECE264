#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
     FILE *file;
     char file_name[255]; //Max file name size
     char ch;
     int counter = 0;

     //If the only input is the program command "./cat-lite", ask
     // for a file name
     if (argc <= 1) {
          printf("Usage: ./cat-lite <filename>\n");
	  return(EXIT_SUCCESS);
     }

     //For loop capturing multiple files to read
     for (counter = 1; counter < argc; counter++) {
          strncpy(file_name, argv[counter], 255);  

	  file = fopen(file_name, "r"); //r - reading
     
	  //Invalid filename is enetered
	  if (file == NULL) {
	       printf("Cannot find file: %s\n", file_name);
	       return(EXIT_SUCCESS);
	  }

	  //Output to console as long as the is no EOF symbol
	  /*while((ch == fgetc(file)) != EOF) {
	       putchar(ch);
	       }*/
	  while (!feof(file)) {
	       ch = fgetc(file);
	       putchar(ch);
	  }

	  fclose(file); //close steam
     }       
     return(EXIT_SUCCESS);
}
