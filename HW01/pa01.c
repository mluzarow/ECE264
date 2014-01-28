#include <stdio.h>
#include <stdlib.h>

// This includes the /definitions/ of the functions that you write
// in this assignment. Including the definitions allows you to use
// the functions in this file.
#include "answer01.h"

void printArray(int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) {
	printf("%d", array[ind]);
	if(ind != len - 1) {
	    printf(", ");
	}
    }
    printf("}");
    // If we don't include a '\n' character, then we need to 
    // include this line to ensure that our output is immediately
    // printed out output.
    fflush(stdout); 
}

void test_arraySum(int * array, int len, int expected)
{
    printArray(array, len);
    int sum = arraySum(array, len);
    printf(". sum = %d, expected = %d.", sum, expected);
    if(sum != expected)
	printf(" FAIL");
    printf("\n");
}

void test_00_arraySum()
{
    printf("Testing arraySum(...)\n");

    // Here we use "static initialization" to create an array
    int array1[] = { -4, -1, 0, 1, 5, 10, 20, 21 };
    int len1 = 8;
    int expected1 = 52;
    test_arraySum(array1, len1, expected1);

    // Our functions must always work... even on empty arrays
    int array2[] = {};
    int len2 = 0;
    int expected2 = 0;
    test_arraySum(array2, len2, expected2);

    int array3[] = {6};
    int len3 = 1;
    int expected3 = 6;
    test_arraySum(array3, len3, expected3);

    int array4[] = {-1, -5, -20, 9};
    int len4 = 4;
    int expected4 = -17;
    test_arraySum(array4, len4, expected4);

    printf("\n"); // Tidy output is easier to use
}

void test_arrayCountNegative(int * array, int len, int expected)
{
    printArray(array, len);
    int count = arrayCountNegative(array,len); 
    printf(". count = %d, expected = %d.", count, expected);
    if(count != expected)
	printf(" FAIL");
    printf("\n");
}

void test_01_arrayCountNegative()
{
    //amount of negatives
    printf("Testing arrayCountNegative(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayCountNegative(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayCountNegative(array2, len2, 0);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayCountNegative(array3, len3, 0);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayCountNegative(array4, len4, 4);

    printf("\n");
}

void test_arrayIsIncreasing(int * array, int len, int expected) {
    printArray(array, len);
    int increasing = arrayIsIncreasing(array, len);
    printf(". increasing = %d, expected = %d.", increasing, expected);
    if (increasing != expected) {
    	printf(" FAIL");
    }
    printf("\n");
}

void test_02_arrayIsIncreasing() {
    //yes -> 1, no -> 0, null -> 1
    printf("Testing arrayIsIncreasing(...)\n");

    int array1[] = {1, 1, 2, 3, 3};
    int len1 = 5;
    test_arrayIsIncreasing(array1, len1, 1);
  
    int array2[] = {1, 2, 0, 4};
    int len2 = 4;
    test_arrayIsIncreasing(array2, len2, 0);

    int array3[] = {};
    int len3 = 0;
    test_arrayIsIncreasing(array3, len3, 1);
    
    int array4[] = {-5, 3, 3};
    int len4 = 3;
    test_arrayIsIncreasing(array4, len4, 1);

    printf("\n");
}

void test_arrayIndexRFind(int needle, int * haystack, int len, int expected) {
    printArray(haystack, len);
    int index = arrayIndexRFind(needle, haystack, len);
    printf(". index = %d, expected = %d.", index, expected);
    if (index != expected) {
    	printf(" FAIL");
    }
    printf("\n");
}

void test_03_arrayIndexRFind() {
    //index of value, not found -> -1
    printf("Testing arrayIndexRFind(...)\n");
    
    int array[] = {1, 4, -5, 4};
    int len = 4;
    
    int needle1 = 1;
    test_arrayIndexRFind(needle1, array, len, 0);
    
    int needle2 = 4;
    test_arrayIndexRFind(needle2, array, len, 3);
    
    int needle3 = 6;
    test_arrayIndexRFind(needle3, array, len, -1);
    
    int needle4 = -5;
    test_arrayIndexRFind(needle4, array, len, 2);

    printf("\n");
}

void test_arrayFindSmallest(int * array, int len, int expected) {
    printArray(array, len);
    int index = arrayFindSmallest(array, len);
    printf(". index = %d, expected = %d.", index, expected);
    if (index != expected) {
    	printf(" FAIL");
    }
    printf("\n");
}

void test_04_arrayFindSmallest() {
    printf("Testing arrayFindSmallest(...)\n");
    
    int array1[] = {3, 4, -5};
    int len1 = 3;
    test_arrayFindSmallest(array1, len1, 2);
    
    int array2[] = {};
    int len2 = 0;
    test_arrayFindSmallest(array2, len2, 0);
    
    int array3[] = {293};
    int len3 = 1;
    test_arrayFindSmallest(array3, len3, 0);

    printf("\n");
}

int main(int argc, char * * argv)
{
    printf("Welcome to ECE264, we are working on PA01.\n\n");

    test_00_arraySum();
    test_01_arrayCountNegative();
    test_02_arrayIsIncreasing();
    test_03_arrayIndexRFind();
    test_04_arrayFindSmallest();

    return EXIT_SUCCESS;
}

