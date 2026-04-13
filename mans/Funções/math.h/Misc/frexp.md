# frexp

#math/misc
## Prototype

```c
#include <math.h>

double frexp(double x, int *exp);
```

## Description

Breaks a floating-point number into its **mantissa and exponent**.

It decomposes `x` such that:  
[  
x = m \times 2^{e}  
]  
where:

- `m` is the mantissa (in range `[0.5, 1)` or `0` if `x = 0`)
    
- `e` is the exponent stored in `*exp`
    

## Parameters

- `x`: The floating-point number to decompose
    
- `exp`: Pointer to an integer where the exponent will be stored
    

## Return Value

- Returns the mantissa `m`
    
- Stores exponent `e` in `*exp`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 20.0;
    int exp;
    
    double mantissa = frexp(x, &exp);

    printf("x = 20.0\n");
    printf("mantissa = %f\n", mantissa);
    printf("exponent = %d\n", exp);

    return (0);
}
```

## Notes

- Internal representation:
    

```c
x = mantissa * 2^exponent
```

- Special case:
    

```c
frexp(0, &exp); // mantissa = 0, exp = 0
```

- Mantissa range:
    
    - Always in `[0.5, 1)` (except zero)
        
- Related functions:
    
    - `ldexp()` → rebuilds number from mantissa + exponent
        
    - `modf()` → splits integer and fractional parts
        
- Common use cases:
    
    - floating-point analysis
        
    - numerical algorithms
        
    - low-level math optimizations