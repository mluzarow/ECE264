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
     free(list);
     stack->list = stack->list->next;
     
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
     int * w_array;
     int i = 0;
     int i_val = 0;

     for (i = 0; i < len; i++) {
          if (!Stack_isEmpty) {
	       if (array[i] > stack->list->value) {
		    i_val = Stack_popFront(stack);
		    w_array[index] = i_val;
		    index++;
		    Stack_pushFront(stack, i_val);
		    i_val = 0;
	       }
	  } else {
	       Stack_pushFront(stack, array[i]); 
	       w_array[index] = array[i];
	       index++; 
	  }
     }
     
     
}

int isStackSortable(int * array, int len) {
     int val = 0;

     return(val);
}

void genShapes(int n) {


}
