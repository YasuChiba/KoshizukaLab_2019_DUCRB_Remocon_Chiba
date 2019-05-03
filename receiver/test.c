#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int test()
{
  char command[256];

   if (snprintf(command, sizeof(command), "ls -l %s", "test.c") > sizeof(command)-1){
    fprintf(stderr,"Length of the strings(filename) is too large.\n");
    exit(1);
  }
  system(command);
}


int main(int argc, char * argv[])
{
test();
/*
  char command[256];
  if (argc != 2){
    fprintf(stderr,"Usage %s filename\n",argv[0]);
    exit(1);
  }
   if (snprintf(command, sizeof(command), "ls -l %s", argv[1]) > sizeof(command)-1){
    fprintf(stderr,"Length of the strings(filename) is too large.\n");
    exit(1);
  }
  system(command);
  */
}

