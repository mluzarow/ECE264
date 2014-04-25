#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "answer12.h"

uint128 alphaTou128(const char * str) {
     uint128 val = 0;
     int len = 0;
     int i = 0;

     while (1) {
          if (str[i] != '\0') {
	       if ((str[i] > 47) && (str[i] < 58)) {
		    len++;  
	       }  
	       i++;
	  } else if (str[i] == '\0') {
	       break;
	  }
     }

     if (str[0] == 45) {
          return(0);
     }
     
     if (len == 0) {
          return(0);
     }
     
     i = 0;

     int tval = 0;
     int j = 0;
     uint128 temp = 0;

     while(len > 0) {
          temp = 0;
          if ((str[i] > 47) && (str[i] < 59)) {
	       tval = str[i] - 48;
	       temp += tval;
	       for (j = 0; j < len - 1; j++) {
		    temp *= 10;
	       }
	       val += temp;
	       len--;
	  }
	  i++;
     }

     return(val);
}

char * u128ToString(uint128 value) {
  //char * out;
  //uint128 divisor = 0;
  //uint128 val2 = value;
  //int tens = 0;

     if (value == 0) {
          return("0");
     }
  
     char str[40] = {0};
     char * s = str + sizeof(str) - 1;
     
     while (value != 0) {
       if (s == str) return 0;

       *--s = "0123456789"[value % 10];
       value /= 10;
     }



     /*
     while(1) {
          val2 = value >> divisor;
	  
	  if (val2 <= 9) {
	       break;
	  } else {
	       tens++;
	       divisor++;
	  }
     }
     
     int i = 0;

     if (tens == 0) {
          out[0] = 48 + value;
	  out[1] = '\0';
     } else {
          for (i = 0; i <= tens; i++) {
	    
	    
	  }
     }
     */
     return(s);
}

int primalityTestParallel(uint128 value, int n_threads) {
     int val = 0;
     

     return(val);
}
