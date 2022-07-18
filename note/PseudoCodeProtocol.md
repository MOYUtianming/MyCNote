>The Protocol for Coding Pseudo Code.

# The general Protocol

1. Same indentation means same block.
2. While for and repeat-until sentence have the same meaning with those corresponding conception in C/C++,Python or Java.
    1. For "for" sentence,the general structure is here:
        ```Cpp
        for flag = <S-num> to/downto <E-num> [by <step-length>]  
            <the loop sentences>  
        ```
        >1. downto operator is used to explain the decrease process.
        >2. the flag hold it's value after the loop.
        >3. the serial list including the limit point ,  
        >   in other words , it means:  
        >   for(**i=S-num**;**i<=E-num**;i = i+step-length)  
3. "//" Head means comments.
4. The sentence like j=i=e means multiple assignment(do i=e first then do j=i)
5. Variables are limited to it's corresponding block.
6. The element of array is used by type:<arrayName>[serialNumber] (Tip : the serial number is starting from 1)
   >e.g. : A[2] refer to the second element in A
7. The multiple data is structured to be "Object" , and "Object" is composed by "attributes".
    1. If we want to use an Object , just use it's name;
    2. If we want to use an attribute of an Object , just use "ObjectName.AttributeName" structure.
8. The name of an array or an object is treated as a point towards their data.
    1. It means in operation "y=x", y.f is changed by x.f too , in other words , after this assignment , y and x towards same data block.
9. The dot mark "." can be used consequently , it means the sentence "y.j.k" is legal.
10. When a point don't toward to any realized data , it should be assigned by "NIL".
11. The method of transferring data to a function is "Value transformation" , it means the function get a copy of the input variable , not use the variable itself.
12. The "return" operation restore the control handle from called processing to the calling processing , usually it will give a return value at the same time. (in this architecture , we can return multiple number values in a single return sentence).
13. The bool operator "AND" and "OR" are "short circuit" , for example , when the first operating number is 0 in "AND" sentence, the whole sentence's value is FALSE , computer won't check the second operating number.
14. The "error" operator means the function is called by fallacious method , the calling processing will give the measure about dealing with the error , so the function don't give the concrete measures.
