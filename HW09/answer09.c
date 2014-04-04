#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "answer09.h"

HuffNode * HuffNode_create(int value) {
     HuffNode * node = malloc(sizeof(HuffNode));
     
     node->value = value;
     node->left = NULL;
     node->right = NULL;

     return(node);
}

void HuffNode_destroy(HuffNode * tree) {
     HuffNode * current = tree;
     HuffNode * nleft = NULL;
     HuffNode * nright = NULL;

     nleft = current->left;
     nright = current->right;
     free(current);

     if (nleft != NULL) {
          HuffNode_destroy(nleft);
     }
     if (nright != NULL) {
          HuffNode_destroy(nright);
     }

     tree = NULL;
}

Stack * Stack_create() {
     Stack * temp = malloc(sizeof(Stack));
     
     temp->head = NULL;

     return(temp);
}

void Stack_destroy(Stack * stack) {
     if (stack == NULL) {
          return;
     }
     
     free(stack->head);
     free(stack);
}

int Stack_isEmpty(Stack * stack) {
     if (stack->head == NULL) {
          return(1);
     } else {
          return(0);
     }
}

HuffNode * Stack_popFront(Stack * stack) {
  HuffNode * tree = NULL;
  StackNode * n = stack->head;

  tree = stack->head->tree;
  stack->head = stack->head->next;
  free(n);

  return(tree);
}

void Stack_pushFront(Stack * stack, HuffNode * tree) {
  StackNode * n = malloc(sizeof(StackNode));
  
  n->tree = tree;
  n->next = stack->head;
  stack->head = n;
}

void Stack_popPopCombinePush(Stack * stack) {
     HuffNode * newChunk = HuffNode_create('o');
     newChunk->right = Stack_popFront(stack);
     newChunk->left = Stack_popFront(stack);
     newChunk->value = newChunk->right->value + newChunk->left->value;
     Stack_pushFront(stack, newChunk);
}

HuffNode * HuffTree_readTextHeader(FILE * fp) {
     char * test = malloc(sizeof(char) * 255);
     int t = 0;
     char temp_char;
     HuffNode * final = NULL;
     int depth = 0;

     int i = 0;
     for (i = 0; i < 255; i++) {
       test[i] = 'a';
     }
     
     while ((temp_char = fgetc(fp)) != EOF) {
          if (temp_char == '1') {
	       test[t] = temp_char;
	       temp_char = fgetc(fp);
	       test[t+1] = temp_char;
	       depth++;
	       t = t + 2;
	  } else if (temp_char == '0') {
	       test[t] = temp_char;
	       depth--;
	       t = t + 1;
	  }
	  if (depth <= 0) {
	       break;
	  }
     }

     Stack * textStack = NULL;
     textStack = Stack_create();

     t = 0;
     while ((test[t] == '1') || (test[t] == '0')) {
          if (test[t] == '0') { //pop pop combine
	       if (textStack->head->next != NULL) {
		    Stack_popPopCombinePush(textStack);
	       }
	       t = t + 1;
	  }  else if (test[t] == '1') { //put on stack
	       if ((test[t+2] == '1') || (test[t+2] == '0')) {	       
		    HuffNode * huffChunk = HuffNode_create(test[t + 1]);
		    Stack_pushFront(textStack, huffChunk);
	       
		    t = t + 2;
	       }
	  }
     }

     final = Stack_popFront(textStack);

     free(test);
     Stack_destroy(textStack);
     return(final);
}

HuffNode * HuffTree_readBinaryHeader(FILE * fp) {
     char * test = malloc(sizeof(char) * 255);
     int t = 0;
     unsigned char temp_char;
     int loc = 0;
     unsigned char fchar;
     int x1;
     int x2; 
     int x3; 
     int x4; 
     int x5; 
     int x6; 
     int x7;
     int x8;
     unsigned char cmd = 0;
     HuffNode * final = NULL;
     unsigned char mask[] = {0b10000000,
			     0b01000000,
			     0b00100000,
			     0b00010000,
			     0b00001000,
			     0b00000100,
			     0b00000010,
			     0b00000001};

     int i = 0;
     for (i = 0; i < 255; i++) {
          test[i] = 'a';
     }

     int depth = 0;
     temp_char = fgetc(fp);
     while(1) {
          if (loc > 7) {
	    temp_char = fgetc(fp);
	    loc = 0;
	  }

          cmd = temp_char & mask[loc];
	  loc++;
	  
	  if (cmd) {
	       test[t] = '1';
	       t++;
	       depth++;

	       if (loc > 7) {
		    loc = 0;
		    temp_char = fgetc(fp);
	       }
	       x1 = temp_char & mask[loc];
	       if (x1) {x1 = 1;}
	       loc++;

	       if (loc > 7) {
		    loc = 0;
		    temp_char = fgetc(fp);
	       }
	       x2 = temp_char & mask[loc];
	       if (x2) {x2 = 1;}
	       loc++;

	       if (loc > 7) {
		    loc = 0;
		    temp_char = fgetc(fp);
	       }
	       x3 = temp_char & mask[loc];
	       if (x3) {x3 = 1;}
	       loc++;

	       if (loc > 7) {
		    loc = 0;
		    temp_char = fgetc(fp);
	       }
	       x4 = temp_char & mask[loc];
	       if (x4) {x4 = 1;}
	       loc++;
	       
	       if (loc > 7) {
		    loc = 0;
		    temp_char = fgetc(fp);
	       }
	       x5 = temp_char & mask[loc];
	       if (x5) {x5 = 1;}
	       loc++;

	       if (loc > 7) {
		    loc = 0;
		    temp_char = fgetc(fp);
	       }
	       x6 = temp_char & mask[loc];
	       if (x6) {x6 = 1;}
	       loc++;

	       if (loc > 7) {
		    loc = 0;
		    temp_char = fgetc(fp);
	       }
	       x7 = temp_char & mask[loc];
	       if (x7) {x7 = 1;}
	       loc++;

	       if (loc > 7) {
		    loc = 0;
		    temp_char = fgetc(fp);
	       }
	       x8 = temp_char & mask[loc];
	       if (x8) {x8 = 1;}
	       loc++;

	       fchar = 2*2*2*2*2*2*2*x1 + 
	         2*2*2*2*2*2*x2 +
	         2*2*2*2*2*x3 + 
	         2*2*2*2*x4 +
	         2*2*2*x5 + 
	         2*2*x6 + 
	         2*x7 +
	         1*x8;
	       test[t] = fchar;
	       t++;

	  } else {
	       test[t] = '0';
	       t++;
	       depth--;
	  }
	  if (depth == 0) {
	    break;
	  }
     }
     
     Stack * textStack = NULL;
     textStack = Stack_create();

     t = 0;
     while ((test[t] == '1') || (test[t] == '0')) {
          if (test[t] == '0') { //pop pop combine
	       if (textStack->head->next != NULL) {
		    Stack_popPopCombinePush(textStack);
	       }
	       t = t + 1;
	  }  else if (test[t] == '1') { //put on stack
	       if ((test[t+2] == '1') || (test[t+2] == '0')) {	    	       
		    HuffNode * huffChunk = HuffNode_create(test[t + 1]);
		    Stack_pushFront(textStack, huffChunk);

		    t = t + 2;
	       }
	  }
     }

     final = Stack_popFront(textStack);

     free(test);
     Stack_destroy(textStack);
     return(final);
}
