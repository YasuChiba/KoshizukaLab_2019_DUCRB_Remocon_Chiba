#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "callRequestMethods.h"


int test()
{
    /*
  char command[256];

   if (snprintf(command, sizeof(command), "ls -l %s", "test.c") > sizeof(command)-1){
    fprintf(stderr,"Length of the strings(filename) is too large.\n");
    exit(1);
  }
  system(command);
  */

 system("python sendRequestPython.py 10");
}


void turnOnLight(int roomNumber) {
   // printf("turn on %d\n",roomNumber);
    printf("start turnOnLight\n");

    test();
    printf("end turnOnLight\n");
}

