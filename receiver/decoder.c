
#include <stdio.h>
#include "decoder.h"

void decode(int* array) {
    //printf("turn on %d\n",roomNumber);
    printf("start decoding \n");
    for(int i = 0; i < 9; i++) {
        printf("%d ",array[i]);
    }

    printf("end decoding \n");

}