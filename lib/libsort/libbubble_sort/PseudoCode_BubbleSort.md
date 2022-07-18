# bubble sort

```Cpp
BUBBLE_SORT(A)
//exchange interfacing elements which is not sorted.
//each sub-loop determined the No.i element's value.
    for i = 1 to A.length-1
        for j = A.length downto i+1
            if A[j]<A[j-1]
                exchange A[j] with A[j-1]
```
