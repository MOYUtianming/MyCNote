#include "insertion_sort.h"
#include <stdio.h>
/**
 * @brief  the Insertion Sort function for integer data.
 * @note
 * @param  DHead: the point towards to the data head.
 * @param  DLength: the length of the data.
 * @retval
 */
void PrintProcess(int* DHead , int DLength)
{
    int k = 0;
    printf("\n");
    for(k = 0; k < DLength; k++) {
        printf("%ld, ", DHead[k]);
    }
    printf("\n");
}

int InsertionSort_int(int* DHead , int DLength)
{
    int j = 0,i = 0;

    PrintProcess(DHead, DLength);
    for(j = 1; j < DLength; j++)
    {
        int key = DHead[j];
        i = j-1;
        while(i >= 0 && DHead[i] > key)
        {
            DHead[i+1] = DHead[i];
            i = i-1;
        }
        DHead[i+1] = key;
        PrintProcess(DHead, DLength);
    }

    return 0;
}
