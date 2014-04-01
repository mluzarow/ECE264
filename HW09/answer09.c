#include <stdio.h>
#include <stdlib.h>

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

     
}

int Stack_isEmpty(Stack * stack) {
     if (stack->head == NULL) {
          return(1);
     } else {
          return(0);
     }
}

HuffNode * Stack_popFront(Stack * stack) {

  return(NULL);
}

void Stack_pushFront(Stack * stack, HuffNode * tree) {


}

void Stack_popPopCombinePush(Stack * stack) {


}

HuffNode * HuffTree_readTextHeader(FILE * fp) {
     char * test;
     int t = 0;
     char temp_char;
     HuffNode * final = NULL;
     int ppc = 0;
     int push = 0;

     while ((temp_char = fgetc(fp)) != EOF) {
          test[t] = temp_char;
	  t++;
     }

     printf("The Header is: %s\n", test);

     fclose(fp);

     t = 0;
     while (test[t] != '2') {
       // printf("%c: NOT 2\n", test[t]);
       if (test[t] == '0') { //pop pop combine
	    
       }  else if (test[t] == '1') { //put on stack
	    
       }
       t = t + 2;
     }

     return(final);
}

HuffNode * HuffTree_readBinaryHeader(FILE * fp) {

  return(NULL);
}
