# M_E

#math/constants
## Prototype

```c
#define M_E 2.71828182845904523536
```

## Description

`M_E` is a mathematical constant defined in `<math.h>` representing Euler’s number _e_.

It is the base of the natural logarithm and is widely used in exponential growth, decay, and continuous compound calculations.

## Value

- Approximate value: `2.71828182845904523536`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 2.0;
    double result = pow(M_E, x);

    printf("e^%.1f = %f\n", x, result);
    return (0);
}
```

## Notes

- It is a **macro constant**, not a function.
    
- Not guaranteed in strict ISO C, but commonly available in `<math.h>` (GNU/POSIX systems).
    
- If missing, you can define it manually:
    

```c
#ifndef M_E
#define M_E 2.71828182845904523536
#endif
```

- Common uses:
    
    - `exp(x)` (natural exponential function)
        
    - continuous growth/decay models
        
    - logarithms (`log` is base _e_)
        

```c
double y = exp(1); // equals M_E
```