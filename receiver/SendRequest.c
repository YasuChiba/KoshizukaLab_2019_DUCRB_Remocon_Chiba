#include "sendRequest.h"
#include <stdio.h>
#include <stdlib.h>



void turnOnLight(int roomNumber) {
    printf("turn on %d\n",roomNumber);

    FILE* fp;
    char  buf[1024];
    char* cmd = "python sendRequestPython.py 10";

   // printf("result : %d\n",system("python sendRequestPython.py 10"));
    if ((fp = popen(cmd, "r")) != NULL) {
        while (fgets(buf, sizeof(buf), fp) != NULL) {
            printf("%s", buf);
        }
        pclose(fp);
        return 0;
    }

}