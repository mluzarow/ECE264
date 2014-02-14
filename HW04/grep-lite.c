#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char ** argv) {
     int counter = 0;
     int fq = 0; //-q "quiet" flag
     int fn = 0; //-n "line-number" flag
     int fv = 0; //-v "invert-match" flag
     char buffer[2000];
     char key[2000];
     int line_number = 1;

     //If only the program name "./grep-lite" is input, exit
     if (argc <= 1) {
          return(EXIT_SUCCESS);
     }
     
     //scan grep-lite inputs for --help
     for (counter = 1; counter < argc; counter++) {
          if (strcmp(argv[counter], "--help") == 0) {
	       printf("Usage: grep-lite [OPTION]... PATTERN\nSearch for PATTERN in standard input. PATTERN is a\nstring. grep-lite will search standard input line by\nline, and (by default) print out those lines which\ncontain pattern as a substring.\n\n  -v, --invert-match     print non-matching lines\n  -n, --line-number      print line number with output\n  -q, --quiet            suppress all output\n\nExit status is 0 if any line is selected, 1 otherwise;\nif any error occurs, then the exit status is 2.\n\n");
	       return(EXIT_SUCCESS);
	  } 
     }

     //last value input to grep-lite is an option and not a pattern
     if (strchr(argv[argc - 1], '-') != NULL) {
          return(2);
     }
     
     strncpy(key, argv[argc - 1], 2000);
     
     //check for options
     for (counter = 1; counter < argc; counter++) {
          if ((strcmp(argv[counter], "-q") == 0) || (strcmp(argv[counter], "--quiet") == 0)) {
	       fq = 1;
	  } else if ((strcmp(argv[counter], "-n") == 0) || (strcmp(argv[counter], "--line-number") == 0)) {
	       fn = 1;
	  } else if ((strcmp(argv[counter], "-v") == 0) || (strcmp(argv[counter], "--invert-match") == 0)){
	       fv = 1;
	  } 
     }


     for (counter = 1; counter < argc; counter++) {
          while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
	       
	       if ((strstr(buffer, key) != NULL) && (fv == 0)) {//value found on line, invert off
		    if ((fn == 1) && (fq == 0)) {//line # on, quiet off
		         printf("%d: %s", line_number, buffer);
		    } else if ((fn == 0) && (fq == 0)) {//line # off, quiet off
		         printf("%s", buffer);
		    }
	       } else if ((strstr(buffer, key) == NULL) && (fv == 1)) {
		    if ((fn == 1) && (fq == 0)) {//line # on, quiet off
		         printf("%d: %s", line_number, buffer);
		    } else if ((fn == 0) && (fq == 0)) {//line # off, quiet off
		         printf("%s", buffer);
		    }
	       }
	       line_number++;
	  }

     }


     return(EXIT_SUCCESS);
}
