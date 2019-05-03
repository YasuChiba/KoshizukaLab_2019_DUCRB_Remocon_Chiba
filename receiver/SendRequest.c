#include "sendRequest.h"
#include <stdio.h>
#include <stdlib.h>



void turnOnLight(int roomNumber) {
    printf("turn on %d\n",roomNumber);
    system("python sendRequestPython.py 100");
}