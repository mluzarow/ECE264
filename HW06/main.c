#include <stdio.h>
#include <stdlib.h>

#include "answer06.h"

int main (int argc, char ** argv) {
     printf("Now partitioning: 1\n");
     partitionAll(1);
     
     printf("Now partitioning: 2\n");
     partitionAll(2);

     printf("Now partitioning: 3\n");
     partitionAll(3);

     printf("Now paritioning: 4\n");
     partitionAll(4);

     return(EXIT_SUCCESS);
}
