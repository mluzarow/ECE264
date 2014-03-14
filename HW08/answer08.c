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
     SparseNode * current = array;
     SparseNode * nleft = NULL;
     SparseNode * nright = NULL;
     int tempInd = 0;
     int minInd = 999999;

     if (current != NULL) {
          nleft = current->left;
          nright = current->right;
	  
	  if (minInd > current->index) {
	       minInd = current->index;
	  }
	  tempInd = SparseArray_getMin(nleft);
	  if (minInd > tempInd) {
	       minInd = tempInd;
	  }
	  tempInd = SparseArray_getMin(nright);
	  if (minInd > tempInd) {
	       minInd = tempInd;
	  }
     }

     return(minInd);
}

int SparseArray_getMax(SparseNode * array) {
     SparseNode * current = array;  
     SparseNode * nleft = NULL;
     SparseNode * nright = NULL;
     int tempInd = 0;
     int maxInd = 1;

     if (current != NULL) {
          nleft = current->left;
	  nright = current->right;
	  
	  if (maxInd < current->index) {
	       maxInd = current->index;
	  }
	  tempInd = SparseArray_getMax(nleft);
	  if (maxInd < tempInd) {
	       maxInd = tempInd;
	  }
	  tempInd = SparseArray_getMax(nright);
	  if (maxInd < tempInd) {
	       maxInd = tempInd;
	  }
     }

    return(maxInd);
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
