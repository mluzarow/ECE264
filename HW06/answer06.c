#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "answer06.h"

#define ALL 0
#define INCREASING 1
#define DECREASING 2
#define ODD 3
#define EVEN 4
#define ODD_AND_EVEN 5
#define PRIME 6
#define TRUE 1
#define FALSE 0

//prototypes
void intHelper(int, int, int*, int, const int);
void intPrinter(int *, int);


void intPrinter(int * buffer, int size) {
     int i = 0;

     printf("=");

     for (i = 0; i <= size; i++) {
          printf("%d", buffer[i]);
	  if (i != size) {
	       printf("+");
	  }
     }

     printf("\n");
}

void intHelper(int value, int sum, int * buffer, int depth, const int mode) {
     while (sum != value) { 
          buffer[depth] += 1;
	  sum++;

	  if (sum == value) {
               if (mode == ALL) {   
		    intPrinter(buffer, depth);
	       } else if (mode == INCREASING) {
		    int x = 0;
		    int error = FALSE;
		    for (x = 0; x < depth; x++) {
		         if (!(buffer[x] < buffer[x + 1])) {
			      error = TRUE;
			 }
		    }
		    if (!error) {
		         intPrinter(buffer, depth);
		    }
	       } else if (mode == DECREASING) {
		    int x = 0;
		    int error = FALSE;
		    for (x = 0; x < depth; x++) {
		         if (!(buffer[x] > buffer[x + 1])) {
			      error = TRUE;
			 }
		    }
		    if (!error) {
		         intPrinter(buffer, depth); 
		    }
	       } else if (mode == ODD) {
		    int x = 0;
		    int error = FALSE;
		    for (x = 0; x <= depth; x++) {
		         if (!(buffer[x] % 2)) {
			      error = TRUE;
			 }
		    }
		    if (!error) {
		         intPrinter(buffer, depth);
		    }
	       } else if (mode == EVEN) {
		    int x = 0;
		    int error = FALSE;
		    for (x = 0; x <= depth; x++) {
		         if (buffer[x] % 2) {
			      error = TRUE;
			 }
		    }
		    if (!error) {
		         intPrinter(buffer, depth);
		    }
	       } else if (mode == ODD_AND_EVEN) {
		    int x = 0;
		    int error = FALSE;
		    for (x = 0; x < depth; x++) {
		         if ((buffer[x] % 2) && (buffer[x + 1] % 2)) {
			      error = TRUE;
			 } else if (!(buffer[x] % 2) && !(buffer[x + 1] % 2)) {
			      error = TRUE;
			 }
		    }
		    if (!error) {
		         intPrinter(buffer, depth);
		    }
	       } else if (mode == PRIME) {
		    int x = 0;
		    int y = 0;
		    int error = FALSE;
		    for (x = 0; x <= depth; x++) {
		         if (buffer[x] == 1) {
			      error = TRUE;
			 } else {
			      for (y = 2; y <= (buffer[x] - 1); y++) {
				   if ((buffer[x] % y) == 0)  {
				        error = TRUE;
				   }
			      }
			 }
		    }
		    if (!error) {
		         intPrinter(buffer, depth);
		    }
	       }
	  } else if (sum < value) { //Sum != value so another # can come after
	       intHelper(value, sum, buffer, depth + 1, mode);
	  }
     }
     buffer[depth] = 0;
}

void partitionAll(int value) {
     int * buffer = malloc(sizeof(int) * value);
     int i = 0;
     for (i = 0; i < value; i++) {
          buffer[i] = 0;
     }

     intHelper(value, 0, buffer, 0, ALL);
     free(buffer);
}

void partitionIncreasing(int value) {
     int * buffer = malloc(sizeof(int) * value);
     int i = 0;
     for (i = 0; i < value; i++) {
          buffer[i] = 0;
     }

     intHelper(value, 0, buffer, 0, INCREASING);
     free(buffer);
}

void partitionDecreasing(int value) {
     int * buffer = malloc(sizeof(int) * value);
     int i = 0;
     for (i = 0; i < value; i++) {
          buffer[i] = 0;
     }

     intHelper(value, 0, buffer, 0, DECREASING);
     free(buffer);
}

void partitionOdd(int value) {
     int * buffer = malloc(sizeof(int) * value);
     int i = 0;
     for (i = 0; i < value; i++) {
          buffer[i] = 0;
     }

     intHelper(value, 0, buffer, 0, ODD);
     free(buffer);
}

void partitionEven(int value) {
     int * buffer = malloc(sizeof(int) * value);
     int i = 0;
     for (i = 0; i < value; i++) {
          buffer[i] = 0;
     }

     intHelper(value, 0, buffer, 0, EVEN);
     free(buffer);
}

void partitionOddAndEven(int value) {
     int * buffer = malloc(sizeof(int) * value);
     int i = 0;
     for (i = 0; i < value; i++) {
          buffer[i] = 0;
     }

     intHelper(value, 0, buffer, 0, ODD_AND_EVEN);
     free(buffer);
}

void partitionPrime(int value) {
     int * buffer = malloc(sizeof(int) * value);
     int i = 0;
     for (i = 0; i < value; i++) {
          buffer[i] = 0;
     }

     intHelper(value, 0, buffer, 0, PRIME);
     free(buffer);
}
