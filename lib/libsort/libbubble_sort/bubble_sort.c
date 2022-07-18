#include "bubble_sort.h"
#include "main.h"
SType SwitchInt(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
    return CORRECT;
}

SType BubbleSort(int* array, int arrayLen)
{
    if(arrayLen <= 0)
        S_REPO(ERROR_WRONG_PARAM);
    int i, j;
    int iLim = arrayLen - 1;
    for(i = 0; i < iLim; i++) {
        for(j = arrayLen - 1; j >0; j--) {
            if((array[j] - array[j - 1]) < 0) {
                SwitchInt(array + j, array + j - 1);
            }
        }
    }
    return CORRECT;
}
