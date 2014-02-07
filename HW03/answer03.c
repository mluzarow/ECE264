//answer03.c is the function file
#include <stdlib.h>
#include <string.h>
#include "answer03.h"

#include <stdio.h> //temp include

/**
 * Append the C-string 'src' to the end of the C-string '*dest'.
 *
 * strcat_ex(...) will append the C-string 'src' to the end of the string
 * at '*dest'. The parameter 'n' is the address of a int that specifies how
 * many characters can safely be stored in '*dest'.
 *
 * If '*dest' is NULL, or if '*dest' is not large enough to contain the result,
 * then strcat_ex will:
 * (1) malloc a new buffer of size 1 + 2 * (strlen(*dest) + strlen(src))
 * (2) set '*n' to the size of the new buffer
 * (3) copy '*dest' into the beginning of the new buffer
 * (4) free the memory '*dest', and then set '*dest' to point to the new buffer
 * (5) concatenate 'src' onto the end of '*dest'.
 *
 * Always returns *dest.
 *
 * Why do we need to pass dest as char * *, and n as int *?
 * Please see the FAQ for an answer.
 *
 * Hint: These <string.h> functions will help: strcat, strcpy, strlen.
 * Hint: Leak no memory.
 **/
char * strcat_ex(char * * dest, int * n, const char * src) {
    //cat src to end of dest, n = len of dest buffer
    char * buffer;

    if (*dest != NULL) {
        buffer = malloc(1 + 2*(strlen(*dest) + strlen(src)));
        strcpy(buffer, *dest);
        strcat(buffer, src);
    } else {
        buffer = malloc(1 + 2*(strlen(src)));
        strcpy(buffer, src);
    }

    *n = sizeof(buffer);
    *dest = buffer;

    return(*dest);
}

/**
 * Takes a string and split it into an array of strings according to delimiter.
 * The memory location '*arrLen' is initialized to the length of the returned
 * array.
 *
 * str: A string to split
 * delims: a string that contains a set of delimiter characters. explode(...)
 *         will split the string at any character that appears in 'delims'.
 * arrLen: pointer to an int that is used to store the resultant length of the
 *         returned array.
 *
 * For example, if delimiter is white space " \t\v\n\r\f", then,
 * int len;
 * char * * strArr = explode("The\nTuring test", " \t\v\n\r\f", &len);
 * // len = 3, strArr[0] is "The", strArr[1] is "Turing", strArr[2] is "test"
 *
 * Hint: you can use <string.h> functions "memcpy" and "strchr"
 *       "memcpy" copies blocks of memory.
 *       "strchr" can be used to tell if a specific character is in delims.
 * Hint: this question is hard; it will help to draw out your algorithm.
 * Hint: read the FAQ...
 **/
char * * explode(const char * str, const char * delims, int * arrLen) {
    int num_delim = 0;
    int counter = 0;

    for (counter = 0; counter < strlen(str); counter++) {
        if (str[counter] == *delims) {
            num_delim++;
        }
    }
        
    printf("str = %s, delims = %d", str, num_delim);
    char ** strArr = malloc((num_delim + 1) * sizeof(char*));

    int arrInd = 0;
    int last = 0;

    for(arrInd = 0; arrInd < strlen(str); arrInd++) {
      if (str[arrInd] == *delims) 
    }

}

//temp main for Code::blocks individual file test
int main(int argc, char ** argv) {
    printf("This is the pa03 HW03 test file.\n\n");

    //Test01
    printf("Now testing strcat_ex(...)\n");
    char * dest;
    dest = "hi";
    int n;
    dest = strcat_ex(&dest, &n, "adsdas");
    printf("dest = %s", dest);
    dest = "blarg2";
    dest = strcat_ex(&dest, &n, "fluff");
    printf("\ndest = %s", dest);
    dest = NULL;
    dest = strcat_ex(&dest, &n, "first null");
    printf("\ndest = %s", dest);

    //Test02
    printf("\n\nNow testing explode(...)\n");
    const char * str_t = "TheLetterStocut";
    const char * delims_t = "S";
    int * arrLen_t = 0;
    char ** buffer;
    buffer = explode(str_t, delims_t, arrLen_t);
    //printf("buffer = ")

    return(EXIT_SUCCESS);
}

