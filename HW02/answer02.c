#include <stdlib.h>
#include "answer02.h"

/**
* Length of C string 'str', excluding the terminating null byte ('\0')
*
* Examples:
* my_strlen("abc"); // 3
* my_strlen(""); // 0
* my_strlen(NULL); // error -- undefined behavior. See README FAQ.
*/
//size_t is some form of unsigned integer
size_t my_strlen(const char * str) {
  int length = 0;         //Length of the given string by character
  int counter = 0;        //Counter for the array of characters
  int notTerminating = 1; //Boolean for breaking if terminating character found
  
  while(notTerminating) {
    if (str[counter] != '\0') {
      length++;
    } else {
      notTerminating = 0;
    }
    counter++;
  }
  return(length); 
}

/**
* Count the number of occurrences of character 'ch' in C string 'str'
*
* Examples:
* my_countchar("foo", 'o'); // 2
*/
int my_countchar(const char * str, char ch) {
  int number = 0;         //Number of occurances
  int counter = 0;        //Counter for the aray of characters
  int notTerminating = 1; //Boolean for breaking if terminating character found
  
  while(notTerminating) {
    if (str[counter] != '\0') {
      if (str[counter] == ch) {
        number++;
      }
    } else {
      notTerminating = 0;
    }
    counter++;
  }
  
  return(number);
}

/**
* Return a pointer to the first occurance of character 'ch' in C string 'str'
* Return NULL if 'ch' is not found.
*
* Note that the terminating '\0' character is considered to be part of the
* string. Thus, if 'ch' is specified as '\0', then return a pointer to the
* null terminator of the string.
*
* Examples:
* const char * str = "Hello World!";
* printf("'%s'\n", my_strchr(str, 'o')); // prints "'o World!'\n"
* printf("'%s'\n", my_strchr(str, 'z')); // prints "'(null)'\n"
* printf("'%s'\n", my_strchr(str, '\0')); // prints "''\n"
*
* Please read the README FAQ before attempting this function.
*/
char * my_strchr(const char * str, int ch) {
  int counter = 0;
  int index = 0;
  int notTerminating = 1;

  while(notTerminating) {
    if (str[counter] != '\0') {
      if (str[counter] == ch) {
	index = counter;
	notTerminating = 0;
      }
    } else {//we are at '\0'
      notTerminating = 0;
      index = counter;
    }
    counter++;
  }
  
  return((char *) &str[index]);
}

/**
* Same as my_strchr(...), except it searches from the right-hand-side
*
* Examples:
* const char * str = "Hello World!";
* printf("'%s'\n", my_strchr(str, 'o')); // prints "'orld!'\n"
* printf("'%s'\n", my_strchr(str, 'z')); // prints "'(null)'\n"
* printf("'%s'\n", my_strchr(str, '\0')); // prints "''\n" *
*/
char * my_strrchr(const char * str, int ch) {
  int counter = 0;
  int index = 0;
  int notTerminating = 1;
  int len = 0;

  len = my_strlen(str) + 1;

  while(notTerminating) {
    if (str[len - counter] == ch) {
      index = len - counter;
      notTerminating = 0;
    } else {
      if ((len - counter) <= 0) {
	notTerminating = 0;
      } else {
	counter++;
      }
    }
  }

  return ((char *) &str[index]);
}

/** Finds the first occurance of C-string 'needle' in C-string 'haystack'
* Return 'haystack' when 'needle' is the empty string (ie, "").
* The terminating null bytes are not compared.
*
* Examples:
* const char * str = "Hello World!";
* printf("'%s'\n", my_strstr(str, "World")); // prints "'World!'\n"
* printf("'%s'\n", my_strstr(str, "")); // prints "'Hello World!'\n"
* printf("'%s'\n", my_strstr(str, "hello")); // prints "'(null)'\n"
*/
char * my_strstr(const char * haystack, const char * needle) {
  int counter = 0;
  //int len1 = 0;
  int len2 = 0;
  int index = 0;
  int notFound = 1;
  int i = 0; 

  //len1 = my_strlen(haystack);
  len2 = my_strlen(needle);

  if (len2 == 0) {
    index = 0;
    notFound = 0;
  }
  
  while(notFound) {
    if (haystack[counter] == needle[0]) {//first letter of needle found

      for (i = 0; i < len2; i++) {
	if (haystack[counter + i] != needle[i]) {//string is not a match
	  i = len2;
	} else {//full string found
	  index = counter; //world begins at first letter point
	  notFound = 0; //break loop
	}
      }
    }
    counter++;
  }

  return((char *) &haystack[index]);
}
  
/**
* Copys C-string 'src' (including the null-byte terminator) into the memory
* pointed to by 'dest'. The strings must not overlap, and 'dest' must be large
* enough to contain 'src', *including* the terminating null-byte.
*
* Returns 'dest'
*
* Examples:
* const char * str = "Hello World!"; // strlen(str) == 12, but 13 bytes with \0
* char buffer[50];
* printf("%s\n", my_strcpy(buffer, str)); // prints "Hello World!\n"
*/
char * my_strcpy(char * dest, const char * src) {
  int counter = 0;
  int notTerminating = 1;

  while(notTerminating) {
    if (src[counter] != '\0') {
      dest[counter] = src[counter];
      counter++;
    } else {
      dest[counter] = '\0';
      notTerminating = 0;
    }
  }

  return(dest);
}

/**
* Append C-string 'src' to C-string 'dest'. 'Dest' must be large enough to
* contain both 'dest' and 'src', *including* the terminating null-byte.
*
* Returns 'dest'
*
* Examples:
* char buffer[50];
* my_strcpy(buffer, "Hello ");
* printf("%s\n", my_strcat(buffer, "Zippy!")); // prints "Hello Zippy!"
*/
char * my_strcat(char * dest, const char * src) {
  int len = 0;
  int counter = 0;
  int write = 1;

  len = my_strlen(dest); //len = counter of dest

  while(write) {
    dest[len] = src[counter];
    
    if (src[counter] == '\0') {
      write = 0;
    }

    counter++;
    len++;
  }

  return(dest);
}

/**
* Returns 1 when 'ch' is a whitespace character, and 0 otherwise.
*
* By default, white-space characters are: space ' ', form-feed '\f',
* newline '\n', carriage return '\r', horizontal tab '\t' and vertical tab '\v'
*
* See the README FAQ for more information.
*
* Examples:
* my_isspace(' '); // 1
* my_isspace('\f'); // 1
* my_isspace('\n'); // 1
* my_isspace('\r'); // 1
* my_isspace('\t'); // 1
* my_isspace('\v'); // 1
* char ch;
* for(ch = 'A'; ch <= 'Z'; ++ch)
* my_isspace(ch); // always 0
*/
int my_isspace(int ch) {
  int isSpace = 0;

  if ((ch < 32) && ((ch != '\0') || (ch != '\a'))) {
    isSpace = 1;
  }

  return(isSpace);
}

/**
* Convert the initial portion of 'str' to an integer.
*
* Implement my_atoi(str) as follows:
* (1) Increment str to skip all white-space characters as defined by
* my_isspace(...)
* (2) If there is a '-' sign, note that 'str' is a negative number, and
* increment str past the minus sign.
* (3) Initialize a return value "ret" to 0. (int ret = 0)
* (4) While '0' <= *str <= '9':
* (4.a) Multiply ret by 10
* (4.b) Add (*str - '0') to ret
* (4.c) Increment str
* (5) If there was a minus sign, return -ret. Otherwise return ret.
*
* Examples:
* my_atoi("0"); // 0
* my_atoi("-12"); // -12
* my_atoi("15th of March would be the ides."); // 15
* my_atoi("4 months to Summer."); // 4
* my_atoi("\n\f\t\v\r 6 white space characters handled correctly."); // 6
* my_atoi("garbage should yield 0"); // 0
*/
int my_atoi(const char * str) {
  int ret = 0;
  int isNegative = 0;
  int counter = 0;
  int len = 0;
  int places = 0;
  int found = 0;
  int start = 0;
  int end = -4;
  int tens = 0;
  int i = 0;

  len = my_strlen(str);

  for (counter = 0; counter <= len; counter++) {
    if (found != 2) {
      if ((str[counter] <= '9') && (str[counter] >= '0')) {
	if (found == 0) {
	  found = 1;
	  start = counter;
	}
	places++;
      } else if (str[counter] == '\0') {
	if (found == 1) {
	  found = 2;
	  end = counter - 1;
	}
	counter = len + 1;
      } else if ((str[counter] == '-') && ((str[counter + 1] <= '9') && (str[counter + 1] >= '0'))) {
	isNegative = 1;
      } else {
	if (found == 1) {
	  found = 2;
	  end = counter - 1;
	  counter = len + 1;
	  
	}
      }
    }
  }
  
  len = end - start + 1; 
  while(len > 0) {
    tens = 1;
    for (i = 0; i < (len - 1); i++) {
      tens *= 10;
    }
    ret += ((str[start] - 48) * tens);
    len--;
    start++;
  }
  if (isNegative) {
    ret = ret * -1;
  }

  return(ret);
}
