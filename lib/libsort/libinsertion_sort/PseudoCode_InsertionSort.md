# insertion sort

```cpp
INSERTION_SORT(A)
    for j = 2 to A.length
        key = A[j]
        //insert A[j] into the sorted sequence A[1..j-1].
        i = j-1
        while i > 1 and A[i] > key
            A[i+1] = A[i]
            i = i-1
        A[i+1]=key
```
