//messing with pointers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main(int argc, char ** argv) {
    int a = 10;
    int * a_p = &a;
    char * b = "Hello";

    printf("a = %d\n", a);       //Prints val of a
    printf("a = %d\n", &a);      //Prints trash
    printf("a = %p\n", a);       //Prints values in allocated memory block found as hexidecimal
    printf("a = %p\n", &a);      //Prints the memory address where a is stored
    printf("a_p = %d\n", * a_p); //Prints integer val of a.
    printf("a_p = %p\n", * a_p); //Prints values in allocated memory block found in pointer a_p as hexidecimal
    printf("a_p = %d\n", a_p);   //???
    printf("a_p = %p\n", a_p);   //Prints the pointer found in pointer a_p
    printf("a_p = %d\n", &a_p);
    printf("a_p = %p\n", &a_p);
    printf("b = %c\n", * b);     //Prints the first letter of the char array, 'H'
    printf("b = %p\n", &b);

    //printf("value = %d, pointer a_p = %p, value a_p = %d", a, a_p, *a_p);

    return(EXIT_SUCCESS);
}
