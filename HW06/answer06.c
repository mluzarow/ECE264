#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "answer06.h"

//prototypes
void intHelper(int, int, int*, int);
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

void intHelper(int value, int sum, int * buffer, int depth) {
     while (sum != value) { 
          buffer[depth] += 1;
	  sum++;

	  if (sum == value) {
               intPrinter(buffer, depth);
	       /*if (depth != 0) {
		    sum -= buffer[depth];
		    }*/
	  } else if (sum < value) { //Sum != value so another # can come after
	       intHelper(value, sum, buffer, depth + 1);
	  }
     }
     buffer[depth] = 0;
}

void partitionAll(int value) {
     int * buffer = malloc(sizeof(int) * value);
     

     intHelper(value, 0, buffer, 0);
     free(buffer);
}

void partitionIncreasing(int value) {


}

void partitionDecreasing(int value) {


}

void partitionOdd(int value) {


}

void partitionEven(int value) {


}

void partitionOddAndEven(int value) {


}

void partitionPrime(int value) {


}
