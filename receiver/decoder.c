
#include <stdio.h>
#include "decoder.h"
#include "callRequestMethods.h"
#include "header.h"


void decode(int* array) {
    //printf("turn on %d\n",roomNumber);
    printf("start decoding \n");
    for(int i = 0; i < CODE_LENGTH; i++) {
        printf("%d ",array[i]);
    }

    printf("\n end decoding \n");
    controllLight(0,304);
}