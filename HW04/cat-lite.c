#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
     FILE *file;
     char file_name[255]; //Max file name size
     //char ch;
     char buffer[255];
     int counter = 0;

     //printf("Current argc value: %d\n", argc);
     
     //If the only input is the program command "./cat-lite", ask
     // for a file name
     if (argc <= 1) {
	  return(EXIT_SUCCESS);
     }

     for (counter = 1; counter < argc; counter ++) {
       //   printf("%s\n", argv[counter]);   
       
          if (strcmp(argv[counter], "--help") == 0) {
	       printf("Usage: cat-lite [--help] [FILE]...\nWith no FILE, or when FILE is -, read standard input.\n\nExamples:\n  cat-lite README   Print the file README to standard output.\n  cat-lite f - g    Print f's contents, then standard input, \n                    then g's contents.\n  cat-lite          Copy standard input to standard output.\n\n");
	       return(EXIT_SUCCESS);
	  } //else if (strcmp(argv[counter], "-") == 0) {
	  // fprintf(stdin);
	  //}
     }

     //For loop capturing multiple files to read
     for (counter = 1; counter < argc; counter++) {
          if (strcmp(argv[counter], "-") == 0) {
	    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		    size_t bytes = fread(buffer, 1, sizeof(buffer), stdin);
		    fwrite(buffer, 1, bytes, stdout);
	       }
	       
	       //fprintf(stin);
	  } else {

	       strncpy(file_name, argv[counter], 255);  

	       file = fopen(file_name, "r"); //r - reading
     
	       //Invalid filename is enetered
	       if (file == NULL) {       
	            return(EXIT_SUCCESS);
	       }

	       //Output to "standard output" as long as the is no EOF symbol
	       while (fgets(buffer, sizeof(buffer), file) != NULL) {
	            printf("%s", buffer);
	       }

	       fclose(file); //close steam
	  }
     }       
     return(EXIT_SUCCESS);
}
