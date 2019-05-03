#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char * argv[])
{
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
}