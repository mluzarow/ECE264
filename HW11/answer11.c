
#include "answer11.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isValidState(const char * state) {
     int i = 0;
     int dups[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     
     if (strlen(state) != 16) {
          return(FALSE);
     }

     for (i = 0; i < 16; i++) {
          if (state[i] == '1') {
	       dups[0] = 1;
	  } else if (state[i] == '2') {
	       dups[1] = 1;
	  }
       case('3'):
	    dups[2] = 1;
	    break;
       case('4'):
	    dups[3] = 1;
	    break;
       case('5'):
	    dups[4] = 1;
	    break;
       case('6'):
	    dups[5] = 1;
	    break;
       case('7'):
	    dups[6] = 1;
	    break;
       case('8'):
	    dups[7] = 1;
	    break;
       case('9'):
	    dups[8] = 1;
	    break;
       case('A'):
	    dups[9] = 1;
	    break;
       case('B'):
	    dups[10] = 1;
	    break;
       case('C'):
	    dups[11] = 1;
	    break;
       case('D'):
	    dups[12] = 1;
	    break;
       case('E'):
	    dups[13] = 1;
	    break;
       case('F'):
	    dups[14] = 1;
	    break;
       case('-'):
	    dups[15] = 1;
       }
       
       for (i = 0; i < 16; i++) {
	    if (dups[i] != 1) {
	         return(FALSE);
	    }
       }
       return(TRUE);
     }
}

/**
 * Prints the puzzle-state as a 2d matrix. 
 * This function is supplied to you.
 */
void printPuzzle(const char * state)
{
    int row, col;
    for(row = 0; row < SIDELENGTH; ++row) {
	for(col = 0; col < SIDELENGTH; ++col) {
	    printf(" %c", state[row*SIDELENGTH + col]);
	}
	printf("\n");
    }
}

/**
 * Print the moves in a move-tree.
 * This function is supplied to you.
 */
void MoveTree_print(MoveTree * node)
{
    if(node == NULL)
	return;
    printf("%s\n", node -> state);
    MoveTree_print(node -> left);
    MoveTree_print(node -> right);
}

