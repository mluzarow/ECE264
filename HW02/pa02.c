#include <stdio.h>
#include <string.h>

#include "answer02.h"

#define BUFFER_LEN 1024

int main(int argc, char * * argv)
{
    printf("ECE264 pa02 custom tester.\n\n");

    const char * s1 = "Hello World!";
    const char * s2 = "";
    const char * s3 = "foo";

    // -- my_strlen, should be: 12, 0, and 3
    printf("\nTesting function my_strlen(...)\n");
    printf("my_strlen(\"%s\") = %d\n", s1, (int) my_strlen(s1));
    printf("my_strlen(\"%s\") = %d\n", s2, (int) my_strlen(s2));
    printf("my_strlen(\"%s\") = %d\n", s3, (int) my_strlen(s3));

    // -- my_countchar, should be: 3, 0, and 2
    printf("\nTesting function my_countchar(...)\n");
    printf("my_countchar(\"%s\", 'l') = %d\n", s1, (int) my_countchar(s1, 'l'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s2, (int) my_countchar(s2, 'o'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s3, (int) my_countchar(s3, 'o'));
    
    // -- my_strchr, should be: "llo World!", "(null)", and ""
    printf("\nTesting function my_strchr(...)\n");
    printf("my_strchr(\"%s\", 'l') = %s\n", s1, my_strchr(s1, 'l'));
    printf("my_strchr(\"%s\", 'o') = %s\n", s2, my_strchr(s2, 'o'));
    printf("my_strchr(\"%s\", '\\0') = %s\n", s3, my_strchr(s3, '\0'));

    // -- my_strrchr, should be: "ld!", "(null)", and "Hello World!"
    printf("\nTesting function my_strrchr(...)\n");
    printf("my_strrchr(\"%s\", 'l') = %s\n", s1, my_strrchr(s1, 'l'));
    printf("my_strrchr(\"%s\", 'o') = %s\n", s2, my_strrchr(s2, 'o'));
    printf("my_strrchr(\"%s\", '\\0') = %s\n", s3, my_strrchr(s3, '\0'));
    printf("my_strrchr(\"%s\", 'F') = %s\n", "Find First 'F' from right", my_strrchr("Find First 'F' from right", 'F'));
    printf("my_strrchr(\"%s\", '!') = %s\n", "!Find last char!", my_strrchr("!Find last char!", '!'));

    
    // -- my_strstr, should be: "World!", "Hello World!", "(null)"
    printf("\nTesting function my_strstr(...)\n");
    printf("my_strstr(\"%s\", \"World\") = %s\n", s1, my_strstr(s1, "World"));
    printf("my_strstr(\"%s\", \"\") = %s\n", s1, my_strstr(s1, ""));
    printf("my_strstr(\"%s\", \"hello\") = %s\n", s1, my_strstr(s1, "hello"));
    

    // -- my_strcpy. For this function you need a buffer where you
    // copy the string to.
    printf("\nTesting function my_strcpy(...)\n");
    char buffer[BUFFER_LEN];
    my_strcpy(buffer, s1);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s1, buffer);
    my_strcpy(buffer, s2);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s2, buffer);
    my_strcpy(buffer, s3);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s3, buffer);

    // -- my_strcat. You will have to do this yourself... just
    // look at my_strcpy for an example, and go from there.
    printf("\nTesting function my_strcat(...)\n");
    my_strcpy(buffer, "Hello ");
    my_strcat(buffer, "Zippy!");
    printf("my_strcat(buffer, \"%s\"), buffer = \"%s\"\n", "Zippy!", buffer); 

    // -- my_isspace. You will have to do this for yourself.
    printf("\nTesting function my_issspace(...)\n");
    printf("my_isspace(\'%c\'), isSpace = %d\n", 'a', my_isspace('a'));
    printf("my_isspace(\'%c\'), isSpace = %d\n", ' ', my_isspace(' '));
    printf("my_isspace(\'\\f\'), isSpace = %d\n", my_isspace('\f'));
    printf("my_isspace(\'\\n\'), isSpace = %d\n", my_isspace('\n'));
    printf("my_isspace(\'\\r\'), isSpace = %d\n", my_isspace('\r'));
    printf("my_isspace(\'\\t\'), isSpace = %d\n", my_isspace('\t'));
    printf("my_isspace(\'\\v\'), isSpace = %d\n", my_isspace('\v'));
    printf("my_isspace(\'%c\'), isSpace = %d\n", 'J', my_isspace('J'));
    printf("my_isspace(\'%c\'), isSpace = %d\n", '7', my_isspace('7'));
    printf("my_isspace(\'\\0\'), isSpace = %d\n", my_isspace('\0'));
    printf("my_isspace(\'\\a\'), isSpace = %d\n", my_isspace('\a')); 

    // -- my_atoi. You will have to do this for yourself.
    printf("\nTesting function my_atoi(...)\n");
    printf("my_atoi(\"0\"), ret = %d\n", my_atoi("0"));
    printf("my_atoi(\"-12\"), ret = %d\n", my_atoi("-12"));
    printf("my_atoi(\"15th of March would be the idea.\"), ret = %d\n", my_atoi("15th of March would be the idea."));
    printf("my_atoi(\"4 months to Summer.\"), ret = %d\n", my_atoi("4 months to Summer."));
    printf("my_atoi(\"\\n\\f\\t\\v\\r 6 white space characters handled correctly.\"), ret = %d\n", my_atoi("\n\f\t\v\r 6 white space characters handled correctly."));
    printf("my_atoi(\"garbage should yield 0\"), ret = %d\n", my_atoi("garbage should yield 0"));
    
    printf("\n\nPrinting Complete\n\n"); 
    
    return EXIT_SUCCESS;
}

