#include <stdio.h>
#include <stdlib.h>
#include <cstring.h>
#include "answer02.h"

void printString(const char * str) {
	printf("String = \"%s\"\n", str);
	
	return(0);	
}

void test_my_strlen(const char * str, int expected) {
	printString(str);
	int length = my_strlen(str);
	printf("Length = %d, Expected = %d", length, expected);
	if (length != expected) {
		printf(" FAIL\n");
	}
	
	return(0);
}

void test_00_my_strlen() {
	printf("Now testing my_strlen(...)\n");
	
	//Test vector 00
	char str1[] = "abc";
	int expected = 3;
	test_my_strlen(str1, expected1);
	
	
	
	return(0);
}

int main(int argc, char * * argv) {
	printf("Testing homework02 with pa02.c test vectors.\n\n")
	
	//tests
	
	return(EXIT_SUCCESS);
}
