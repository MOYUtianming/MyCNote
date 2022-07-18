# the Pseudo code for Horner formula

the Horner formula is used to compute the summary of polynomial like this:
$$y = \sum_{i=0}^{n}a_i x^i$$
Horner formula prove that the equalization before equals to
$$a_0+x(a_1+x(a_2+x(...)))$$

```Cpp
HORNER_POLYNOMIAL(CA,X)
//CA = Coefficient_Array
//X = the actual x;
    y = 0
    for i = 0 to CA.length
        y = CA[i]+X*y
    return y
```
