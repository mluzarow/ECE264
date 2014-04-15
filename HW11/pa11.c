#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void printUsage(void);

int main (int argc, char ** argv) {
     //argv[1] = stage
     //argv[2] = state
     //argv[3] = moves

     if (argc != 4) {
          printUsage();
	  return(EXIT_SUCCESS);
     }
     
     if (isValidState(argv[2]) == 0) {
          printf("There is an error in your state input.\n\n");
	  return(EXIT_SUCCESS);
     }


     return (EXIT_SUCCESS);
}

void printUsage() {
  printf("\n"
	 "   Usage: ./answer11 <stage> <state> <moves>\n"
	 "\n"
	 "   <stage> can be '1'\n"
	 "\n"
	 "   <stage> must be a combination of values, '1' through 'F',\n"
	 "   including '-', which make up a 4 by 4 puzzle.\n"
	 "   Example: '123456789ABCDEF-'\n"
	 "\n"
	 "   <moves> must be a sequence of movement commands, each\n"
	 "   denoted by their primary letter.  \n"
	 "   U = Up, D = Down, L = left, R = right\n"
	 "   Example: 'UUDDLRLR'\n"
	 "\n");
}
