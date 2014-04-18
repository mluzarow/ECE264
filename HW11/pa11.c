#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "answer11.h"

void printUsage(void);

int main (int argc, char ** argv) {
     //argv[1] = stage
     //argv[2] = state
     //argv[3] = moves
     if (argv[1][0] == '1') {
          if (argc != 4) {
	       printUsage();
	       return(EXIT_FAILURE);
	  }
	  /*
	  if ((argv[1][0] != '1') && (argv[1][0] != '2') && (argv[1][0] != '3')) {
	       printf("Incorrect stage value.\n");
	       return(EXIT_FAILURE);
	  } 
	  */
	  if (isValidState(argv[2]) == 0) {
	       printf("The state is not valid.\n");
	       return(EXIT_FAILURE);
	  }
       
	  if (isValidMoveList(argv[3]) == 0) {
	       printf("The move list is not valid.\n");
	       return(EXIT_FAILURE);
	  }
	  
	  processMoveList(argv[2], argv[3]);
     } else if (argv[1][0] == '2') {
          if (argc != 4) {
	       printUsage();
	       return(EXIT_FAILURE);
	  }
	  if (isValidState(argv[2]) == 0) {
	       printf("The state is not valid.\n");
	       return(EXIT_FAILURE);
	  }

	  if ((argv[3][0] < '0') || (argv[3][0] > '9')) {
	       printf("The move number is not valid.\n");
	       return(EXIT_FAILURE);
	  }

	  int val = argv[3][0] - 48;
	  MoveTree * tree = generateAll(argv[2], val);
	  MoveTree_print(tree);
	  MoveTree_destroy(tree);
     } else if (argv[1][0] == '3') {
       
       /* MoveTree * tree = NULL;
       	  tree = MoveTree_insert(tree, "123456789ABCDEF-", "L");
	  //printf("Initial tree. State: %s, Moves: %s\n", tree->state, tree->moves);
	  MoveTree_print(tree);
	  tree = MoveTree_insert(tree, "123456789ABCDE-F", "LL");
	  //printf("Final tree.   State: %s, Moves: %s\n", tree->state, tree->moves);
	  MoveTree_print(tree);
	  tree = MoveTree_insert(tree, "123456789ABCD-EF", "LLL");
	  MoveTree_print(tree);
	  MoveTree_destroy(tree);*/
     } else {
          printf("The stage number is not valid.\n");
	  return(EXIT_FAILURE);
     }
     //MoveTree * f = MoveTree_create(argv[2],argv[3]);
     //MoveTree_destroy(f);

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
