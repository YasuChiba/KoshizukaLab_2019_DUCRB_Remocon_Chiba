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

void controllLight(int isTurnOn, int roomNumber) {
    char command[40] = {'\0'};

    snprintf(command, 40, "python sendRequestPython.py %d %d %d", 0, isTurnOn == 1, roomNumber);
    printf("start sending light controll command\n");
    printf("%s \n", command);
    system(command);
}
