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
     int done = 0;

     if ((index == 0) || (value == 0)) {
          return(array);
     }

     while (!done) {
          if (current == NULL) {//Have nothing made yet
	       insertion = SparseNode_create(index, value);
	       return(insertion);
	       //current = insertion;
	       //done = 1;
	  } else if (current->index > index) { //index is smaller than our position
	       if (current->left == NULL) { //cannot move left any further
	            insertion = SparseNode_create(index, value); 
		    current->left = insertion;
		    done = 1;
	       } else {//we can move one more left
	            current = current->left;
	       }
	  } else if (current->index < index) { //given index is larger than our position
	       if (current->right == NULL) {
		    insertion = SparseNode_create(index, value);
		    current->right = insertion;
		    done = 1;
	       } else {
		    current = current->right;
	       }
	  } else if (current->index == index) {
	       current->value = value;
	       done = 1;
	  }
     }
     
     return(array);
}

SparseNode * SparseArray_build(int * indices, int * value, int length) {
     SparseNode * list = NULL;
     int i = 0;

     for (i = 0; i < length; i++) {
          list = SparseArray_insert(list, indices[i], value[i]);
     }
     return(list);
}

void SparseArray_destroy(SparseNode * array) {
     SparseNode * current = array;
     SparseNode * nleft = NULL;
     SparseNode * nright = NULL;
     
     nleft = current->left;
     nright = current->right;
     free(current);
     
     if (nleft != NULL) {
          SparseArray_destroy(nleft);
     }
     if (nright != NULL) {
          SparseArray_destroy(nright);
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
