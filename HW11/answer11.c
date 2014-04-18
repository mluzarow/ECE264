#include "answer11.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void generateAllHelper(MoveTree*, int, const char*, char*, int);

char * solve(char * state) {
     MoveTree * tree = NULL;   
     tree = generateAll("123456789ABCDEF-", 9);
     MoveTree * node = NULL;
     node = MoveTree_find(tree, state);
         
     if(node == NULL) {
          return(NULL);
     } else {
       //char temp[9];
       //int i = 0;
       // for (i = 0; i < 9; i++) {
       //      if ((node->moves[i] == 'U') || (node->moves[i] == 'D') || (node->moves[i] == 'L') || (node->moves[i] == 'R')) {
       //	    temp[i] = node->moves[i];
       //      } else {
       //	    temp[i] = '\0';
       //	    break;
       //      }
       // }
	  //char * temp2 = temp;
          char * f = strdup(node->moves);
      
	  MoveTree_destroy(tree);
	  //char * f = temp;
	  //free(temp);
          return(f);
     }

     MoveTree_destroy(tree);
     return("test");
}

void generateAllHelper(MoveTree * root, int n_moves, const char * state, char * movelist, int ind) {
        if (ind >= n_moves) {
             return;
	}
	const char * moves = "UDLR";
	int i = 0;

	for (i = 0; i < 4; i++) {
	     char * dup_state = strdup(state);

	     if (move(dup_state, moves[i]) == 0) {
	          free(dup_state);
	     } else {
	          movelist[ind] = moves[i];
		  int i = 0;
		  for (i = ind + 1; i < n_moves; i++) {
		       movelist[i] = ' ';
		  }
		 
		  MoveTree * dup = MoveTree_find(root, dup_state);
		  if (dup == NULL) {
		       root = MoveTree_insert(root, dup_state, movelist);
		       generateAllHelper(root, n_moves, dup_state, movelist, ind + 1);
		  }
		  free(dup_state);
		  
	     }
	}
}

MoveTree * generateAll(char * state, int n_moves) {
     if (n_moves == 0) {
          MoveTree * temp = NULL;
          temp = MoveTree_insert(temp, state, "\0");
          return(temp);
     }
     
     char movelist[n_moves + 1];
     int i = 0;
     for (i = 0; i < n_moves; i++) {
          movelist[i] = ' ';
     }
     movelist[n_moves] = '\0';
   
     MoveTree * tree = NULL;
     tree = MoveTree_insert(NULL, state, "\0");
     generateAllHelper(tree, n_moves, state, movelist, 0);
     return(tree);
}

MoveTree * MoveTree_find(MoveTree * node, const char * state) {
     MoveTree * found = NULL;
     MoveTree * current = node;
     
     if (current == NULL) {
          return;
     }

     if (strcmp(current->state, state) == 0) {
          found = current;
	  return(found);
     } else if (strcmp(current->state, state) < 0) {
          found = MoveTree_find(current->left, state);
     } else if (strcmp(current->state, state) > 0) {
          found = MoveTree_find(current->right, state);
     }
     return(found);
}

MoveTree * MoveTree_insert(MoveTree * node, const char * state, const char * moves) {
     MoveTree * current = node;
     MoveTree * old = NULL;
     MoveTree * insertion = NULL;
     int old_dir = -1;
     int done = 0;

     while(!done) {
          if (current == NULL) {//Have nothing made yet
	       insertion = MoveTree_create(state, moves);
	       if (old != NULL) {
		    if (old_dir == 0) {
		         old->left = insertion;
		    } else if (old_dir == 1) {
		         old->right = insertion;
		    }
		    return(node);
	       }
	       return(insertion);
	  }/* else if (MoveTree_find(node, state) != NULL) {
	       MoveTree * dup = MoveTree_find(state);
	       if (strlen(dup->moves) > strlen(moves)) {
		    insertion = MoveTree_create(state, moves);
		    inesrtion->left = dup->left;
		    insertion->right = dup->right;
		    dup->left = NULL;
		    dup->right = NULL;
		    if (old != NULL) {
		         if (old_dir == 0) {
			      old->left = insertion;
			 } else if (old_dir == 1) {
			      old->right = insertion;
			 }
			 MoveTree_destroy(dup);
			 return(node);
		    }
		    MoveTree_destroy(dup);
		    return(insertion);
	       } else {
		 return(node);
		 }*/

	  else if (strcmp(current->state, state) == 0) {//found duplicate
	       if (strlen(current->moves) > strlen(moves)) {//replace if old has more moves
		    insertion = MoveTree_create(state, moves);
		    insertion->left = current->left;
		    insertion->right = current->right;
		    current->left = NULL;
		    current->right = NULL;
		    if (old != NULL) {//the insertion is not the new head
		         if (old_dir == 0) {//insertion is to the left of a node
			      old->left = insertion; 
			 } else if (old_dir == 1) {//insertion is to the right of a node
			      old->right = insertion;
			 }
			 MoveTree_destroy(node);
			 return(node);
		    }
		    MoveTree_destroy(current);
		    return(insertion);
	       } else {
		    return(node);
		    }
	  } else if (strcmp(current->state, state) < 0) {
	       old = current;
	       old_dir = 0;
	       current = current->left;
	  } else if (strcmp(current->state, state) > 0) {
	       old = current;
	       old_dir = 1;
	       current = current->right;
	  }
     }
     return(node);
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

