#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "answer07.h"

//function for splitting lists to sort
void SplitLists(List*, List**, List**);

/*
// A ListNode structure for a linked list of strings.
typedef struct ListNode_st
{
    char * str;
    struct ListNode_st * next;
} List;
*/

/**
 * Create a new list-node with the passed string. 
 * str should be copied (with strdup).
 */
List * List_createNode(const char * str) {
     List * list = malloc(sizeof(List));
     list->str = strdup(str);
     list->next = NULL;
    
     return(list);
}

/**
 * Free all memory associated with the linked list, including memory for
 * constained strings. Must safely handle NULL lists.
 */
void List_destroy(List * list) {
     List * current = list;
     List * next;

     //The "list" is the head node 
     while (current != NULL) {
          next = current->next;
	  free(current->str);
	  free(current);
	  current = next;
     }
     list = NULL;
}

/**
 * Length of a linked list. 
 * The length of "NULL" is 0.
 */
int List_length(List * list) {
     List * n_search = list;
     int length = 0;
     
     while (n_search != NULL) {
          length++;
          n_search = n_search->next;
     }
  
     return(length);
}

/**
 * Merge two sorted lists to produce a final sorted list.
 * 
 * 'lhs' and 'rhs' are two sorted linked-list. Read 'left-hand-side' and 'right-
 * hand-side'. Note that either (or both) could be NULL, signifying the empty
 * list.
 * 'compar' is a function that is used to compare two nodes. This parameter is
 * similar to the parameter in qsort(...), except that it only compares two
 * strings. You can pass 'strcmp' to this function if you want to sort lists in
 * ascending order.
 *
 * When implementing this function, do not call List_createNode(...) or
 * malloc(...) Instead, think about how to build a new list by:
 * (1) Create a new (empty -- i.e., NULL) list where we build the result. You 
 *     will need to track the first and last node of this list.
 * (2) In a while-loop:
 * (2.a) Use compar to identify whether the front node of lhs or rhs is smaller.
 *       Remember that lhs or rhs could be NULL. 
 * (2.b) Move the front node of 'lhs/rhs' to the end of the result list. 
 *
 * You will need to consider what happens when 'lhs' or 'rhs' becomes NULL.
 *
 * Well-written code should be 20-30 lines long, including comments and spacing.
 * If your code is longer than this, then you may save time by rethinking your
 * approach.
 */
List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*)) {
     List * merged = NULL;
     
     //base
     if (lhs == NULL) {
          return(rhs);
     } else if (rhs == NULL) {
          return(lhs);
     }

     //check compar function for direction
     //if (compar("b", "a") < 0 ) { //function is backwards
       //if (strcmp(lhs->str, rhs->str) > 0) {
	 //merged = lhs;
	 // merged->next = List_merged(lhs->next, rhs, strcmp
     //}  
     //recursion
     if (compar(lhs->str, rhs->str) <= 0) { //lhs->str <= rhs->str
          merged = lhs;
	  merged->next = List_merge(lhs->next, rhs, compar);
     } else {  //lhs->str > rhs->str
          merged = rhs;
	  merged->next = List_merge(lhs, rhs->next, compar);
     }
     return(merged);
}

/** 
 * Sorts the list's elements using the merge-sort algorithm.
 * Merge-sort is a recursive algorithm. See the README for hints.
 * 
 * The brief instructions are as follows:
 *
 * (1) Base case: 
 * Lists of length 0 or 1 are already (defacto) sorted. In this case, return
 * 'list'.
 *
 * (2) Recursive case: 
 * (2.a) Split the linked-list into two approx. equal sized lists.
 * (2.b) Call List_sort(...) on each of these smaller lists.
 * (2.c) Call List_merge(...) to merge the now sorted smaller lists into a 
 *       single larger sorted list, which you return.
 *
 * Well-written code should be 20-30 lines long, including comments and spacing.
 * If your code is longer than this, then you may save time by rethinking your
 * approach.
 */
List * List_sort(List * list, int (*compar)(const char *, const char*)) {
     List * head = list;
     //List * a;
     //List * b;
     List * done;
     if ((head == NULL) || (head->next == NULL)) { //given a blank list
          return(head);
     }
  
     //Split head into a and b sublists
     //SplitLists(head, &a, &b);      
     List * fast;
     List * slow;
     List * fRef;
     List * bRef;

     if ((head == NULL) || (head->next == NULL)) {
       //length < 2
       fRef = head;
       bRef = NULL;
     } else {
       slow = head;
       fast = head->next;
       
       //Advance fast 2 nodes, slow 1 node
       while (fast != NULL) {
	 fast = fast->next;

	 if (fast != NULL) {
	   fast = fast->next;
	   slow = slow->next;
	 }
       }
       
       fRef = head;
       bRef = slow->next;
       slow->next = NULL;
    }

     fRef = List_sort(fRef, compar);
     bRef = List_sort(bRef, compar);
     //Sort each sublist
     //done
     done = List_merge(fRef, bRef, compar);
     return(done);
}

void SplitLists(List * source, List ** frontRef, List ** backRef) {
     List * fast;
     List * slow;
     
     if ((source == NULL) || (source->next == NULL)) {
          //length < 2
          *frontRef = source;
          *backRef = NULL;
     } else {
          slow = source;
          fast = source->next;
          
          //Advance fast 2 nodes, advance slow 1 node
          while (fast != NULL) {
               fast = fast->next;
               
               if (fast != NULL) {
                    slow = slow->next;
                    fast = fast->next;
               }
          }
          
          //slow is before the midpoint in the list, so split it in 2
          *frontRef = source;
          *backRef = slow->next;
          slow->next = NULL;
     }
}
