#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char ** argv) {
     FILE *file;
     int counter = 0;

     //If only the program name "./grep-lite" is input, exit
     if (argc <= 1) {
          return(EXIT_SUCCESS);
     }

     for (counter = 1; counter < argc; counter++) {
          file = fopen(argv[counter], "r");
	  

     }


     return(EXIT_SUCCESS);
}
