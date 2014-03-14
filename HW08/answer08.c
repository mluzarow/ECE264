#include <stdlib.h>
#include "answer08.h"

SparseNode * SparseNode_create(int index, int value) {
     SparseNode * list = malloc(sizeof(SparseNode));
     list->index = index; //(*list).index = index;
     list->value = value;
     list->left = NULL;
     list->right = NULL;

     return(list);
}

SparseNode * SparseArray_insert(SparseNode * array, int index, int value) {
     
     SparseNode * current = array;
     SparseNode * insertion = NULL;
     //SparseNode * temp = NULL;
     SparseNode * next = NULL;
     //SparseNode * write = NULL;
     //int pPos = -1; //Previous position of the imaginary index arrow pointing doodly
     int done = 0;

     while (!done) {
          if (current == NULL) {//Have nothing made yet
	       insertion = SparseNode_create(index, value);
	       return(insertion);
	       current = insertion;
	       done = 1;
	  } else if (current->index > index) { //index is smaller than our position
	       if (current->left == NULL) { //cannot move left any further
	            insertion = SparseNode_create(index, value); 
		    //insertion->right = current;
		    current->left = insertion;
		    //return(insertion);
		    done = 1;
	       } else {//we can move one more left
	            current = current->left;
		    //done = 1;
	       }
	  } else if (current->index < index) { //given index is larger than our position
	    //next = current->right;

	       //current = next;
	       done = 1;
	  } //else if (current->index == index) { //we found it! insert
	    //   done = 1;
	  //} 
     }
     
     return(current);
}

SparseNode * SparseArray_build(int * indices, int * value, int length) {
     SparseNode * list = NULL;

     return(list);
}

void SparseArray_destroy(SparseNode * array) {
     SparseNode * current = array;
     SparseNode * next = NULL;

     while (current != NULL) {
          next = current->right;
	  free(current);
	  current = next;
     }
     array = NULL;
}

int SparseArray_getMin(SparseNode * array) {
     int minVal = 0;

     return(minVal);
}

int SparseArray_getMax(SparseNode * array) {
    int maxVal = 0;

    return(maxVal);
}

SparseNode * SparseArray_getNode(SparseNode * array, int index) {
     SparseNode * list = NULL;

     return(list);
}

SparseNode * SparseArray_remove(SparseNode * array, int index) {
     SparseNode * list = NULL;

     return(list);
}

SparseNode * SparseArray_copy(SparseNode * array) {
     SparseNode * list = NULL;

     return(list);
}

SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2) {
     SparseNode * list = NULL;

     return(list);
}
