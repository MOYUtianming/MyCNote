#include "merge_sort.h"

static SType MergeCore(int* DHead, int DL, int Mp, int DR)
{
    int LNum = Mp - DL + 1;
    int RNum = DR - Mp;
    int* L = (int*)malloc(LNum + 1);
    int* R = (int*)malloc(RNum + 1);
    int flag = 0;

    for(flag = 0; flag < LNum; flag++) {
        L[flag] = DHead[DL+flag];
    }
    for(flag = 0; flag < RNum; flag++) {
        R[flag] = DHead[Mp+1+flag];
    }
// the sentry flag is used to escape from check array overflow each time.
/* for example:
    A = {4, 3, 2, 1, INT_MAX,        }
    B = {5, 4, 3, 2, 1,      INT_MAX }
    when we want to merge B's last legal data , All A's legal data has been used,
    but we still can use A's sentry to compare with B's last legal data;
*/
    L[LNum] = INT_MAX;
    R[RNum] = INT_MAX;
//be careful about Lp and Rp.
    int Lp = 0;
    int Rp = 0;
//run DR-DL+1 times;
    for (flag = DL; flag <= DR; flag++) {
        //be careful about array overflow
        if (L[Lp] <= R[Rp]) {
            DHead[flag] = L[Lp];
            Lp++;
        } else {
            DHead[flag] = R[Rp];
            Rp++;
        }
    }

    return CORRECT;
}

SType MergeSort(int* DHead , int DL , int DR)
{
    if (DL<DR) {
        int Mp = (DL+DR)/2;
        MergeSort(DHead , DL   , Mp);
        MergeSort(DHead , Mp+1 , DR);

        MergeCore(DHead , DL , Mp , DR);
    }
    // else: do nothing, then the prior MergeSort process will do MergeCore;
    return CORRECT;
}
