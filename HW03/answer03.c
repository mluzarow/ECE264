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



    return(*dest);
}

//temp main for Code::blocks individual file test
int main(int argc, char ** argv) {
    printf("\n\nTHis is the pa03 HW03 test file.\n\n");

    //Test01
    printf("Now testing strcat_ex(...)\n");
    char * dest;
    int * n;
    const char * src = "Static";
    dest = strcat_ex(&dest, n, src);

    return(EXIT_SUCCESS);
}

