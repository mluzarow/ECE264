#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
     int counter = 0;

     for (counter = 1; counter < (argc - 1); counter++) {
          printf("%s ", argv[counter]);
     }
  
     printf("%s\n", argv[argc - 1]);

     return(EXIT_SUCCESS);
}
