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
          if (argc != 3) {
	       printUsage();
	       return(EXIT_FAILURE);
	  }
	  
	  if (isValidState(argv[2]) == 0) {
	       printf("The state is not valid.\n");
	       return(EXIT_FAILURE);
	  }

          char * f_moves = solve(argv[2]);
	  // char temp[10];
	  //temp = f_moves;
	  //	  printf("%s", f_moves);
	  
	  int i = 0;
	  int size = 0;
	  while(1) {
	       if ((f_moves[i] == 'U') || (f_moves[i] == 'D') || (f_moves[i] == 'L') || (f_moves[i] == 'R')) {
		    if (f_moves[i] == 'U') {
		         f_moves[i] = 'D';
		    } else if (f_moves[i] == 'D') {
		         f_moves[i] = 'U';
		    } else if (f_moves[i] == 'L') {
		         f_moves[i] = 'R';
		    } else if (f_moves[i] == 'R') {
		         f_moves[i] = 'L';
		    }
		 size++;
		 i++;
	       } else {
		    break;
	       }
	  }
	  i = 0;
	  char * temp = f_moves;
	  for (i = 0; i < size; i++) {
	       f_moves[(size - 1) - i] = temp[i];
	  }
	  //int size = strlen(f_moves);
	  /*i = 0;
	  for (i = 0; i < size; i++) {
	    printf("%c", f_moves[i]);
	    }*/
	  //printf("\n");
	  printf("%s", f_moves);
	  free(f_moves);
	  // int i = 0;
	  //for (i = 0; i < strlen(f_moves); i++) {
	  //printf("%c", f_moves[i]);
	  //}
	  //int i = 0;
	  //while(f_moves[i] != '\0') {
	  //     printf("%c", f_moves[i]);
	  //     i++
	  //}
	  //printf("\n");
	  //printf("%s\n", f_moves);
	  
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
