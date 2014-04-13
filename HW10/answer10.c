#include <stdio.h>
#include <stdlib.h>
#include "answer10.h"
/*
typedef struct list_node_t {
     int value;
     struct list_node_t * next;
} ListNode;

typedef struct stack_t {
     ListNode * list;
} Stack;

*/

void ListNode_destroy(ListNode * list);

Stack * Stack_create() {
     Stack * temp = malloc(sizeof(Stack));

     temp->list = NULL;

     return(temp);
}

void Stack_destroy(Stack * stack) {
     if (stack == NULL) {
          return;
     }
     
     if (stack->list != NULL) {
          ListNode_destroy(stack->list);
     }

     free(stack);
}

void ListNode_destroy(ListNode * list) {
     ListNode * current = list;
     ListNode * nnext = NULL;

     nnext = current->next;
     free(current);

     if (nnext != NULL) {
          ListNode_destroy(nnext);
     }
}

int Stack_isEmpty(Stack * stack) {
     if (stack->list == NULL) {
          return(1);
     } else {
          return(0);
     }
}

int Stack_popFront(Stack * stack) {
     ListNode * list = NULL;
     int val;

     list = stack->list;
     val = list->value;
     stack->list = stack->list->next;    
     free(list);

     return(val);
}

void Stack_pushFront(Stack * stack, int value) {
     ListNode * node = malloc(sizeof(ListNode));
     
     node->value = value;
     node->next = stack->list;
     stack->list = node;
}

void stackSort(int * array, int len) {
     Stack * stack = Stack_create();
     int index = 0;
     int w_array[100];
     int i = 0;
     int i_val = 0;
     int junk = 0;

     if (!isStackSortable(array, len)) {
          Stack_destroy(stack);
          return;
     }

     for (i = 0; i < len; i++) {//place every value in array correctly onto stack
          if (Stack_isEmpty(stack) == 0) {//check if stack is fresh
	       while ((array[i] > stack->list->value) && (Stack_isEmpty(stack) == 0)) {
		    i_val = Stack_popFront(stack);
		    w_array[index] = i_val;
		    index++;
		    i_val = 0;
		    junk = 1;
		    if (stack->list == NULL) {
		         w_array[index] = array[i];
			 index++;
		         break;
		    }
		    if ((stack->list->value > array[i])) {
		         w_array[index] = array[i];
			 index++;
			 break;
		    }
	       }
	       if (junk) {
		 /*if ((array[i] < stack->list->value) && (stack->list != NULL))  {
		         w_array[index] = array[i];
			 index++;
			 }*/
		    while (index > 0) {
		         index--;
		         Stack_pushFront(stack, w_array[index]);
		    }
		    junk = 0;
		    index = 0;
	       }
	       if (array[i] < stack->list->value) {
		    Stack_pushFront(stack, array[i]);
	       }
	  } else {
	       Stack_pushFront(stack, array[i]); 
	  }
     }
     for (i = 0; i < len; i++) {//remove all stack values
          array[i] = Stack_popFront(stack);
     }
     Stack_destroy(stack);
}

int isStackSortable(int * array, int len) {
     int sortable = 1;
     int pass = 1;
     int left[20];
     int right[20];
     int rlen = 0;
     int llen = 0;
     int i = 0;
     int largest_num = 0;
     int largest_index = -1;

     if (array[0] == 0) {
       return(sortable);
     }

     if (len <= 2) {
       return(sortable);
     }

     for (i = 0; i < 20; i++) {
          left[i] = 0;
	  right[i] = 0;
     }

     //if (len > 2) {
          //find largest value
          for (i = 0; i < len; i++) {
	       if (array[i] > largest_num) {
		    largest_num = array[i];
		    largest_index = i;
	       }
	  }

	  /*if (largest_index == (len - 1)) {
	       return(sortable);
	  } else if (largest_index == 0) {
	       return(!sortable);
	       }*/

	  //split array into left and right
	  for (i = 0; i < largest_index; i++) {
	       left[i] = array[i];
	       llen++;
	  }
	  for (i = llen + 1; i < len; i++) {
	       right[i - (llen + 1)] = array[i];
	       rlen++;
	  } 

	  largest_num = 99;
	  i = 0;

	  if (right[0] == 0) {//null right
	       pass = isStackSortable(left, llen);
	       if (pass == 0) {
	            sortable = 0;
	       }
	  } else {
	       //find smallest right val
	       while (right[i] != 0) {
		    if (right[i] < largest_num) {
		         largest_num = right[i];
		    }
		    i++;
	       }
	  }

	  i = 0;
	  
	  if (left[0] == 0) {
	       pass = isStackSortable(right, rlen);
	       if (pass == 0) {
		    sortable = 0;
	       }
	  } else {
	       //check left to see if any vals are more than largest
	       while (left[i] != 0) {
		    if (left[i] > largest_num) {
		         sortable = 0;
			 return(sortable);
		    }
		    i++;
	       }
	  }
	  
	  pass = isStackSortable(left, llen);
	  if (pass == 0) {
	    sortable = 0;
	  }
	  pass = isStackSortable(right, rlen);
	  if (pass == 0) {
	    sortable = 0;
	  }
	  //}
     return(sortable);
}

void genShapes(int n) {


}
