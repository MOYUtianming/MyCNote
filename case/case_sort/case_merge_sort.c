#include "main.h"
#include "merge_sort.h"

int main()
{
    int data[] = {52,51,26,25,61,23,94,87,61};
    int dataBack[] = {52,51,26,25,61,23,94,87,61};
    int dataNum = sizeof(data)/sizeof(data[0]);
    MergeSort(data, 0, dataNum - 1);
    int i;
    for(i = 0; i < dataNum; i++) {
        printf("sn[%ld]data[%ld]dataBack[%ld]\n", i, data[i], dataBack[i]);
    }
}
