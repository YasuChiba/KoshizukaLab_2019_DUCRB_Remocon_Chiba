#include "decoder.h"

//一つのコマンドの長さ
#define CODE_LENGTH 10

void decode(int* array) {
    //printf("turn on %d\n",roomNumber);
    printf("start decoding \n");
    for(int i = 0; i < CODE_LENGTH; i++) {
        printf("%d ",array[i]);
    }

    printf("end decoding \n");

}