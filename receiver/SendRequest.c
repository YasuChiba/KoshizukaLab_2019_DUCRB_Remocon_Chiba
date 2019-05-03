#include "sendRequest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test()
{
  char command[256];

   if (snprintf(command, sizeof(command), "ls -l %s", "test.c") > sizeof(command)-1){
    fprintf(stderr,"Length of the strings(filename) is too large.\n");
    exit(1);
  }
  system(command);
}


void turnOnLight(int roomNumber) {
    printf("turn on %d\n",roomNumber);

    //system("ls -l test.c");
    test();
}

