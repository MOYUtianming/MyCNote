#include "main.h"
#include "../../lib/libsort/libbubble_sort/bubble_sort.h"

int main(int argc, char** argv)
{
    int data[] = {14,51,26,25,61,23,94,87,61};
    int dataBack[] = {14,51,26,25,61,23,94,87,61};
    int dataNum = sizeof(data)/sizeof(data[0]);
    struct timeval tStart, tEnd;
    mingw_gettimeofday(&tStart, NULL);
    BubbleSort(data, dataNum);
    mingw_gettimeofday(&tEnd, NULL);
    printf("time[%ld.%06ld~%ld.%06ld]timeDiff[%ld.%06ld]\n", tStart.tv_sec, tStart.tv_usec, tEnd.tv_sec, tEnd.tv_usec, tEnd.tv_sec - tStart.tv_sec, tEnd.tv_usec - tStart.tv_usec);
    int i;
    for(i = 0; i < dataNum; i++) {
        printf("sn[%ld]data[%ld]dataBack[%ld]\n", i, data[i], dataBack[i]);
    }
    return 0;
}
