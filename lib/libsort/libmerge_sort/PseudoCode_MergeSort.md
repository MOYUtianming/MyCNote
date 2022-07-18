# merge sort

```Cpp
MERGE(A , DL , Mp , DR)
    LNum = Mp-DL+1
    // or can replaced by DR-Mp
    RNum = DR-(Mp+1)+1
    define L[1..LNum+1]
    define R[1..RNum+1]
    // init the Left array and Right array
    for flag = 1 to LNum
        L[flag] = A[DL+flag]
    for flag = 1 to RNum
        R[flag] = A[Mp+1+flag]
    //  add sentry number to escape from check array overflow.
    L[LNum+1] = +INF;
    R[RNum+1] = +INF;
    //init Left point and Right point
    define Lp = 1;
    define Rp = 1;
    for flag = DL to DR
        if L[Lp]<= R[Rp]
            A[flag] = L[Lp]
            Lp = Lp+1
        else
            A[flag] = R[Rp]
            Rp = Rp+1

```

```Cpp
MERGE_SORT(A , DL , DR)
    if DL < DR
        //Mp become the Max integer less than or equal to (DL+DR)/2.
        Mp = (LMint)((DL+DR)/2)
        MERGE_SORT(A , DL , Mp)
        MERGE_SORT(A , Mp+1 , DR)
        MERGE(A , DL , Mp , DR)
    else
        A[DL] = A[DL];
```
