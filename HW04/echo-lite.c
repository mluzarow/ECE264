#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
     int counter = 0;

     //Since the first value in the argv array is the program
     // command "./echo-lite", skip that part of the array.
     for (counter = 1; counter <= (argc - 1); counter++) {
          printf("%s ", argv[counter]);
     }
     printf("\n");
     
     return(EXIT_SUCCESS);
}
