//answer03.c is the function file
#include <stdlib.h>
#include <string.h>
#include "answer03.h"

#include <stdio.h> //temp include

int comp(const void*, const void*);

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
 /*************************************************************************************
  * strcat_ex will concatenate string @ dest and string @ src
  * char ** dest is the destination space for concatenation
  * int * n is the address of # of characters that can be stored in dest
  * char * src is the string to be appended to the end of the string in dest
  ************************************************************************************/

char * strcat_ex(char * * dest, int * n, const char * src) {
    char * buffer; //intermediate location

    if (*dest != NULL) { //if dest in not NULL, alloc for string in dest and src
        buffer = malloc(1 + 2*(strlen(*dest) + strlen(src)));
        strcpy(buffer, *dest);
        strcat(buffer, src);
    } else { //if dest is NULL, ignore dest alloc
        buffer = malloc(1 + 2*(strlen(src)));
        strcpy(buffer, src);
    }

    *n = strlen(buffer); //length is the size of the intermediate string array
    free(*dest); //dealloc space used by dest
    *dest = buffer; //copy buffer string to dest for output

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
    int num_delim = 0; //Number of delims in the source string str
    int counter = 0;   //Loop counter

    //Finds the number of delims on source string str
    for (counter = 0; counter < strlen(str); counter++) {
        if (str[counter] == *delims) {
            num_delim++;
        }
    }

    //allocates memory to output string array strArr
    char ** strArr = malloc((num_delim + 1) * sizeof(char*));
    printf("str = %s, delims = %d\n", str, num_delim);

    int arrInd = 0; //Index for output string array strArr
    int last = 0;   //last place where delim was found

    for(counter = 0; counter <= strlen(str); counter++) {
        if ((str[counter] == *delims) || (str[counter] == '\0')) {
            char * newString = malloc(sizeof(char)*50); //Temp string for storing separated string

            //copies str string at location (str + last) of (counter - last) length
            // to location newString
            memcpy(newString, str + last, counter - last);
            last = 1 + counter;             //Add end character
            newString[strlen(newString)] = '\0';

            strArr[arrInd] = newString; //copy value in newString to output string array
            printf("strArr[%d] = %s\n", arrInd, strArr[arrInd]);
            arrInd++; //Increment output string array index
        }
    }
    *arrLen = arrInd;
    return(strArr);
}

/**
 * Takes an array of strings, and concatenates the elements into a single
 * string, placing 'glue' between each successive element.
 *
 * strArr: an array of strings
 * len: the length of the array 'strArr'
 * glue: string to concatenate between each element of 'strArr'
 *
 * For example:
 * int len;
 * char * * strArr = explode("100 224 147 80", " ", &len);
 * char * str = implode(strArr, len, ", ");
 * printf("(%s)\n", str); // (100, 224, 147, 80)
 *
 * Hint: use strcat_ex in a for loop.
 */
char * implode(char * * strArr, int len, const char * glue) {
    char * str;
    int counter = 0;
    int len_str = 0;

    for(counter = 0; counter < len; counter++) {
        len_str = strlen(strArr[counter]);
        printf("The length of strArr[%d] (%s) = %d\n", counter, strArr[counter], len_str);
        str = strcat_ex(&str, &len_str, strArr[counter]);
    }

    return(str);
}
int comp(const void * a, const void * b) {
    return(*(int*)a - *(int*)b);
}
/**
 * Takes an array of C-strings, and sorts them alphabetically, ascending.
 *
 * arrString: an array of strings
 * len: length of the array 'arrString'
 *
 * For example,
 * int len;
 * char * * strArr = explode("lady beatle brew", " ", &len);
 * sortStringArray(strArr, len);
 * char * str = implode(strArr, len, " ");
 * printf("%s\n"); // beatle brew lady
 *
 * Hint: use the <stdlib.h> function "qsort"
 * Hint: you must _clearly_ understand the typecasts.
 */
void sortStringArray(char * * arrString, int len) {
    qsort(arrString, len, sizeof(char*), comp);
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
    printf("First string: %s\nSecond String: %s\nLength n: %d\nFinal String: %s\n", "hi", "adsdas", n, dest);
    dest = "blarg2";
    dest = strcat_ex(&dest, &n, "fluff");
    printf("First string: %s\nSecond String: %s\nLength n: %d\nFinal String: %s\n", "blarg2", "fluff", n, dest);
    dest = NULL;
    dest = strcat_ex(&dest, &n, "first null");
    printf("First string: %s\nSecond String: %s\nLength n: %d\nFinal String: %s\n", "", "first null", n, dest);

    //Test02
    printf("\n\nNow testing explode(...)\n");
    const char * str_t = "A Lot More Values Astronomical";
    const char * delims_t = " ";
    int * arrLen_t = 0;
    char ** buffer;
    printf("Using input string: \"%s\"\nwith delimiter set: \"%s\"\n", str_t, delims_t);
    buffer = explode(str_t, delims_t, arrLen_t);
    printf("arrLen = %d\n", &arrLen_t);

    //Test03
    printf("\n\nNow testing implode(...)\n");
    char * finalArr;
    finalArr = implode(buffer, 5, ", ");
    printf("finalArr = %s\n", finalArr);

    return(EXIT_SUCCESS);
}

