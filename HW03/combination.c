#include <stdlib.h>
#include <string.h>
#include "answer03.h"

#include <stdio.h> //temp include
int comp(char**, char**);
int comp2(const void *, const void *);

typedef struct List List;

struct List {
    void* data;
    List* next;
};

List* newList(void* data) {
    List* list = (List*) malloc(sizeof(List));
    list->data = data;
    list->next = NULL;
    return (list);
}

void noop(void* x) {
    //destroy list takes function as input; use function instead of NULL
};

List* destroyList(List* list, void (*destroyer)(void*)) {
    while (list != NULL) {
        List* to_destroy = list;
        list = list->next;
        destroyer(to_destroy->data);
        free(to_destroy);
    }
}

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
    printf("First string: %s\nSecond String: %s\nLength n: %d\nFinal String: %s\n\n", "", "first null", n, dest);

    //Test02
    char* test02_str1 = "this is a    string";
    char* test02_delim1 = " ";
    int i = 0;
    int test02_output_len;
    printf("Input: \"%s\"\n", test02_str1);
    printf("Delim: \"%s\"\n", test02_delim1);

    char** test02_output_str = explode(test02_str1, test02_delim1, &test02_output_len);

    printf("words: %d\n", test02_output_len);

    for (i = 0; i < test02_output_len; i++) {
        printf("%3d: %s\n", i, test02_output_str[i]);
        free(test02_output_str[i]);
    }

    free(test02_output_str);

    char* test02_str2 = "A, big thing made of stuff";
    char* test02_delim2 = " \n";
    printf("Input: \"%s\"\n", test02_str2);
    printf("Delim: \"%s\"\n", test02_delim2);

    test02_output_str = explode(test02_str2, test02_delim2, &test02_output_len);

    printf("words: %d\n", test02_output_len);

    for (i = 0; i < test02_output_len; i++) {
        printf("%3d: %s\n", i, test02_output_str[i]);
        free(test02_output_str[i]);
    }

    free(test02_output_str);

    //Test03
    int test03_str1_len;
    char ** test03_str1 = explode("Beta Alpha Zeta Omega", " ", &test03_str1_len);
    const char * test03_glue1 = ", ";

    char * test03_output_str = implode(test03_str1, test03_str1_len, test03_glue1);
    printf("Output: %s\n", test03_output_str);

    //Test04
    sortStringArray(test03_str1, 4);

    for (i = 0; i < 4; i++) {
        printf("%3d: %s\n", i, test03_str1[i]);
        free(test03_str1[i]);
    }

    free(test03_str1);

    //Test05

    char test05_str[5] = "dcba";

    sortStringCharacters(test05_str);

    printf("Sorted: %s", test05_str);
    return(EXIT_SUCCESS);
}

void sortStringCharacters(char * str) {
    char str2[strlen(str)];
    int j = 0;
    int i = 0;

    for (j = 0; j < strlen(str); j++) {
        str2[j] = *(str + j);
    }
    qsort(str2, strlen(str2), sizeof(char), comp2);

    /*for (i = 0; i < strlen(str); i++) {
       printf("str2[%d] = %c\n", i, str2[i]);
       str = str2;
        printf("str[%d] = %c\n", i, str[i]);
    }*/
    const char * fff = str2;
    strcpy(str, fff);
}

int comp2(const void * a, const void * b) {
    if (*(char*)a < *(char*)b) {
         return(-1);
    } else if ((*(char*)a == *(char*)b)) {
        return(0);
    } else if ((*(char*)a > *(char*)b)) {
        return(1);
    }
}

void sortStringArray(char * * arrString, int len) {
    qsort(arrString, len, sizeof(char*), (int (*) (const void *, const void *)) comp);
}
int comp(char ** a, char ** b) {
    return(strcmp(*a,*b));
}

char * implode(char * * strArr, int len, const char * glue) {
    char * str = (char*) malloc(len * sizeof(char));
    int counter = 0;
    int len_str = 0;
    int len_glue = strlen(glue);
    int len_escape = 1;

    str = str - 2;
    for(counter = 0; counter < len; counter++) {
        len_str = strlen(strArr[counter]);

        str = strcat_ex(&str, &len_str, strArr[counter]);

        if (counter == len-1) {

            str = strcat_ex(&str, &len_escape, "\0");
        } else {
            str = strcat_ex(&str, &len_glue, glue);
        }
    }

    return(str);
}

char** explode(const char* str, const char* delims, int* arrLen) {
    List head;
    head.next = NULL;
    List* tail = &head;
    int list_size = 0;

    const char* ptr = str;
    const char* start = ptr;
    int sub_len = 0;

    while (1) {
        if ((*ptr == '\0') || (strchr(delims, *ptr) != NULL)) { //found end or delim
            if (sub_len > 0) { //there is a word to be copied
                char* new_str = (char*) malloc((sub_len + 1) * sizeof(char));
                memcpy(new_str, start, sub_len); //location, start, how far
                new_str[sub_len] = '\0'; //add ec to end of word
                List* new_node = newList(new_str); //put word in list
                tail->next = new_node; //move
                tail = new_node;
                list_size++; //one more space
            }

            start = ptr + 1; //start at one letter over (skip delim)
            sub_len = 0; //reset

            if (*ptr == '\0') { //Exit loop if we get to the end of the phrase
                break;
            }
        }
        else { //no delim or end found, keep going
            ++sub_len;
        }

        ++ptr; //move along the phrase
    }


    *arrLen = list_size; //length (# words) is amount of list entries
    char** str_arr = (char**) malloc(list_size * sizeof(char*));
    char** arr_ptr = str_arr; //link arr_ptr to str_arr

    List* list = head.next;
    while (list != NULL) { //if still entry in list
        *arr_ptr = list->data; //get entry
        ++arr_ptr; //next word
        list = list->next; //next entry
    }

    destroyList(head.next, &noop); //remove from memory

    return (str_arr);
}

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


