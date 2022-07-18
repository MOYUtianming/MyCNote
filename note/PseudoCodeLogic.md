>The Pseudo Code for useful Logic function.

```Cpp
BIT_REVERSE_ALL(Num)
    num = NOT Num
    return num
```

```Cpp
BIT_CONFIGURATION_CONTROL(Num , Mask , Type)
    num = num
    if Type = "SpecialBitTo0"
        num = Num AND Mask
    else if Type = "SpecialBitTo1"
        num = Num OR Mask
    else if Type = "SpecialBitReverse"
        num = Num XOR Mask
    else
        return 1
    return num
```
