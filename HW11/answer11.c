#include "answer11.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

MoveTree * MoveTree_find(MoveTree * node, const char * state) {
     MoveTree * val = NULL;

     if (strcmp(node->state, state) == 0) {
          return(node); 
     } else {
          if (node->left != NULL) {
	       val = MoveTree_find(node->left, state);
	  }
	  if (node->right != NULL) {
	       
	  }
     }
}

MoveTree * MoveTree_insert(MoveTree * node, const char * state, const char * moves) {
     MoveTree * tree = NULL;
  
     if (node == NULL) {
	  return(tree);
     }
     

}

void MoveTree_destroy(MoveTree * node) {
     MoveTree * current = node;
     MoveTree * nleft = current->left;
     MoveTree * nright = current->right;
     free(current->state);
     free(current->moves);
     free(current);

     if (nleft != NULL) {
          MoveTree_destroy(nleft);
     }
     if (nright != NULL) {
          MoveTree_destroy(nright);
     }

     node = NULL;
}

MoveTree * MoveTree_create(const char * state, const char * moves) {
     MoveTree * tree = malloc(sizeof(MoveTree));
     tree->state = strdup(state);
     tree->moves = strdup(moves);
     tree->left = NULL;
     tree->right = NULL;

     return(tree);
}

int move(char * state, char m) {
     int pos = 0;
     int npos = 0;
     int row = 0;
     int col = 0;
     int i = 0;
     char temp;

     for (i = 0; i < 16; i++) {
          if (state[i] == '-') {
	       pos = i;
	       break;
	  }
     }
    
     row = pos / SIDELENGTH;
     col = pos % SIDELENGTH;

     //     printf("pos = %d, row: %d, col: %d\n",pos, row, col);

     if (m == 'U') {
          row = row - 1;
     } else if (m == 'D') {
          row = row + 1;
     } else if (m == 'L') {
          col = col - 1;
     } else if (m == 'R') {
          col = col + 1;
     }

     // printf("row: %d, col: %d\n", row, col);
     
     if ((row < 0) || (row >= SIDELENGTH)) {
          return(FALSE);
     }
     if ((col < 0) || (col >= SIDELENGTH)) {
          return(FALSE);
     }

     npos = row * SIDELENGTH + col;

     // printf("npos: %d\n", npos);

     temp = state[npos];
     state[npos] = '-';
     state[pos] = temp;

     return(TRUE);
}

void processMoveList(char * state, const char * moveList) {
     int len = strlen(moveList);
     int i = 0;
     
     for (i = 0; i < len; i++) {
          if (move(state, moveList[i]) == 0) {
	       printf("I\n");
	       return;
	  }
     }
     printf("%s\n", state);
}

int isValidMoveList(const char * moveList) {
     int len = strlen(moveList);
     int i = 0;

     for (i = 0; i < len; i++) {
          if ((moveList[i] != 'U') && (moveList[i] != 'D') && (moveList[i] != 'R') && (moveList[i] != 'L')) {
	       return(FALSE);
	  }
     }

     return(TRUE);
}

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
	  }  else if (state[i] == '3') {
	       dups[2] = 1;
	  }  else if (state[i] == '4') {
	       dups[3] = 1;
	  }  else if (state[i] == '5') {
	       dups[4] = 1;
	  }  else if (state[i] == '6') {
	       dups[5] = 1;
	  }  else if (state[i] == '7') {
	       dups[6] = 1;
	  }  else if (state[i] == '8') {
	       dups[7] = 1;
	  }  else if (state[i] == '9') {
	       dups[8] = 1;
	  }  else if (state[i] == 'A') {
	       dups[9] = 1;
	  }  else if (state[i] == 'B') {
	       dups[10] = 1;
	  }  else if (state[i] == 'C') {
	       dups[11] = 1;
	  }  else if (state[i] == 'D') {
	       dups[12] = 1;
	  }  else if (state[i] == 'E') {
	       dups[13] = 1;
	  }  else if (state[i] == 'F') {
	       dups[14] = 1;
	  }  else if (state[i] == '-') {
	       dups[15] = 1;
	  }
     }
       
     for (i = 0; i < 16; i++) {
          if (dups[i] != 1) {
	    return(FALSE);
	  }
     }
     return(TRUE);
}

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

void MoveTree_print(MoveTree * node)
{
    if(node == NULL)
	return;
    printf("%s\n", node -> state);
    MoveTree_print(node -> left);
    MoveTree_print(node -> right);
}

