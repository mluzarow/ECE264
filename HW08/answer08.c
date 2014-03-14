#include <stdlib.h>
#include "answer08.h"

SparseNode* CopyHelper(SparseNode*, SparseNode*);
void RemoveHelper(SparseNode*, int, SparseNode**, SparseNode**, int*);

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
     SparseNode * found = NULL;
     SparseNode * possible = NULL;
     SparseNode * current = array;
     SparseNode * nleft = NULL;
     SparseNode * nright = NULL;

     if (current != NULL) {
          nleft = current->left;
	  nright = current->right;
	  
	  if (current->index == index) {
	       found = current;
	  }
	  possible = SparseArray_getNode(nleft, index);
	  if ((possible != NULL) && (possible->index == index)) {
	       found = possible;
	  }
	  possible = SparseArray_getNode(nright, index);
	  if ((possible != NULL) &&  (possible->index == index)) {
	       found = possible;
	  }
     }

     return(found);
}

SparseNode * SparseArray_remove(SparseNode * array, int index) {
     SparseNode * list = array;
     SparseNode * parent = NULL;
     SparseNode * child = NULL;
     SparseNode * suc = NULL;
     int exists = 0;

     if ((array == NULL) || (index == 0)) {//no array
          return(array);
     }

     RemoveHelper(array, index, &parent, &child, &exists);

     if (exists == 0) {
          return(array);
     }

     if ((child->left != NULL) && (child->right != NULL)) {
          parent = child;
	  suc = child->right;

	  while (suc->left != NULL) {
	       parent = suc;
	       suc = suc->left;
	  }

	  child->index = suc->index;
	  child->value = suc->value;
	  child = suc;
     }

     if ((child->left == NULL) && (child->right == NULL)) {
          if (parent->right == child) {
	       parent->right = NULL;
	  } else {
	       parent->left = NULL;
	  }

	  free(child);
	  return(list);
     }

     if ((child->left == NULL) && (child->right != NULL)) {
          if (parent->right == child) {
	       parent->left = child->right;
	  } else {
	       parent->right = child->right;
	  }
	  
	  free(child);
	  return(list);
     }

     if ((child->left != NULL) && (child->right == NULL)) {
          if (parent->left == child) {
	       parent->left = child->left;
	  } else {
	       parent->right = child->left;
	  }
	  
	  free(child);
	  return(list);
     }

     return(list);
}

void RemoveHelper(SparseNode * array, int index, SparseNode ** parent, SparseNode ** child, int * exists) {
     SparseNode * temp = NULL;
     
     temp = array;
     *exists = 0;
     *parent = NULL;

     while (temp != NULL) {
          if (temp->index == index) {
	       *exists = 1;
	       *child = temp;
	       return;
	  }
	  *parent = temp;

	  if (temp->index > index) {
	       temp = temp->left;
	  } else {
	       temp = temp->right;
	  }
     }
}

SparseNode * SparseArray_copy(SparseNode * array) {
     SparseNode * list = NULL;
     
     if (array != NULL) {
          list = SparseNode_create(array->index, array->value);
     } else {
          return(list);
     }
     
     list = CopyHelper(list, array);

     return(list);
}

SparseNode * CopyHelper(SparseNode * list, SparseNode * array) {
     SparseNode * nleft = NULL;
     SparseNode * nright = NULL;
     
     nleft = array->left;
     nright = array->right;

     if (nleft != NULL) {
          list->left = SparseNode_create(nleft->index, nleft->value);
	  list->left = CopyHelper(list->left, array->left);
     }
     if (nright != NULL) {
          list->right = SparseNode_create(nright->index, nright->value);
	  list->right = CopyHelper(list->right, array->right);
     }

     return(list);
}

SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2) {
     SparseNode * list1 = NULL;
     SparseNode * list2 = NULL;
     //SparseNode * temp = NULL;

     list1 = array_1;
     list2 = array_2;
     
     if ((list1 == NULL) && (list2 == NULL)) {
          return(NULL);
     } else if (list1 == NULL) {
          return(list2);
     } else if (list2 == NULL) {
          return(list1);
     } 

     return(list1);
}
