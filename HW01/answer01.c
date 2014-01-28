#include <stdlib.h>
#include "answer01.h" 

/** Return the sum of the array elements. */
int arraySum(int * array, int len) {
  int counter = 0; //array index counter
  int sum = 0;     //current sum of values in array

  for (counter = 0; counter < len; counter++) {
    sum += array[counter];
  }

  return(sum);
}

/** How many elements are less than zero. 
 * 
 * Examples:
 * int array[] = { 1, 4, -5, 4 };
 * int len = 4;
 * int count = arrayCountNegative(array,len); // count == 1
 */
int arrayCountNegative(int * array, int len) {
  int counter = 0; //array index counter
  int sum = 0;     //sum of values less than 0

  for (counter = 0; counter < len; counter++) {
    if (array[counter] < 0) {
      sum++;
    }
  }

  return(sum);
}

/** Are the array elements increasing.
 * Return 1 (i.e., TRUE) if every element of the array is 
 * greater than or equal to preceding elements. Also return 1 
 * if the array is empty.
 * Return 0 if there is one or more elements that are smaller
 * than some preceding element.
 * 
 * Examples:
 * int array1[] = { 1, 1, 2, 3, 3 };
 * int len1 = 5;
 * int array2[] = { 1, 2, 0, 4 };
 * int len2 = 4;
 * int isInc1 = arrayIsIncreasing(array1, len1); // isInc1 == 1
 * int isInc2 = arrayIsIncreasing(array2, len2); // isInc2 == 0
 * int isInc3 = arrayIsIncreasing(NULL, 0);      // isInc3 == 1
 */
int arrayIsIncreasing(int * array, int len) {    
  int increasing = 1; //T = 1, F = 0, Null = 1
  int counter = 0;    //array index counter
  
  if (len <= 1) { //if array is null or has only one value
    increasing = 1; //increasing -> true
  } else { //array has 2+ values
    for (counter = 1; counter < len; counter++) {
      if (array[counter] < array[counter - 1]) {
	increasing = 0; //increasing -> false
	counter = len; //break loop and save computing time
      }
    }
  }

  return(increasing);
}

// Searching arrays
/** Find a needle (some integer) in a haystack (an array)
* If the array "haystack" contains the integer "needle", then
* return the _index_ of needle. If "haystack" contains "needle"
* multiple times, then return the right-most (greatest) index.
* If "needle" is not in "haystack", then return -1.
*
* Examples:
* int haystack[] = { 1, 4, -5, 4 };
* int len = 4;
* int x1 = arrayIndexRFind(1, haystack, len); // x1 == 0
* int x2 = arrayIndexRFind(4, haystack, len); // x2 == 3
* int x3 = arrayIndexRFind(6, haystack, len); // x3 == -1
*/
int arrayIndexRFind(int needle, const int * haystack, int len) {
  int counter = 0;
  int index = -1;

  for (counter = 0; counter < len; counter++) {
    if (haystack[counter] == needle) {
      index = counter;
    }
  } 	
  return(index);
}

/** Return the _index_ of the smallest element in the array.
 * If the smallest element is duplicated, then return the smallest index.
 * If the array is empty (has zero length), then return 0.
 * 
 * Examples:
 * int array[] = { 3, 4, -5 };
 * int len = 3;
 * int ind1 = arrayFindSmallest(array, len); // ind1 == 2
 */
int arrayFindSmallest(int * array, int len) {
  int counter = 0;
  int index = 0;
  int value = 0;

  if (len == 0) {
    index = 0;
  } else {
    for (counter = 0; counter < len; counter++) {
      if (array[counter] < value) {
	index = counter;
	value = array[counter];
      }
    }
  }
  
  return(index);
}
