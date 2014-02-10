#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
     FILE *file;
     char file_name[255];
     char ch;

     file = fopen(file_name, "r");
     
     if (file == NULL) {
       printf("Doesn't exist\n");
       return(EXIT_SUCCESS);
     }

     while((ch == fgetc(file)) != EOF) {
       putchar(ch);
     }

     fclose(file);
       
     return(EXIT_SUCCESS);
}
