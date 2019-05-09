
#include <stdio.h>
#include "decoder.h"
#include "callRequestMethods.h"
#include "header.h"


int bin2dec(int *data, int length) {
  int result = 0;

  for(int i = 0; i < length; i++) {
    result += data[i] * (1 << (length - 1 - i));
  }
  return result;
}

void decode(int* array) {
    int roomNumber = 0;

    printf("start decoding \n");
    for(int i = 0; i < CODE_LENGTH; i++) {
        printf("%d ",array[i]);
    }

    roomNumber = bin2dec(array + 2, 9);
    printf("\ndecode result:  %d %d %d\n", array[0],array[1],roomNumber);
    printf("end decoding \n");

    if(array[0] == 0) {
        controllLight(array[1],roomNumber);
    }
}