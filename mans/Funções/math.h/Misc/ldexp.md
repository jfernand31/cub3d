# ldexp

#math/misc
## Prototype

```c
#include <math.h>

double ldexp(double x, int exp);
```

## Description

Computes the value of a floating-point number from a **mantissa and exponent**, effectively the inverse of `frexp`.

Mathematically:  
[  
ldexp(x, exp) = x \times 2^{exp}  
]

## Parameters

- `x`: The mantissa (floating-point value)
    
- `exp`: The exponent (power of 2)
    

## Return Value

- Returns ( x \times 2^{exp} ) as a `double`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double mantissa = 0.625;
    int exp = 5;

    double result = ldexp(mantissa, exp);

    printf("ldexp(0.625, 5) = %f\n", result);
    return (0);
}
```

## Notes

- Equivalent to:
    

```c
x * pow(2, exp)
```

- Special case:
    

```c
ldexp(0, exp) = 0
```

- Relationship:
    
    - Inverse of `frexp`
        

```c
x = frexp(value, &exp)
value = ldexp(x, exp)
```

- Common use cases:
    
    - floating-point reconstruction
        
    - numerical algorithms
        
    - low-level math optimization
        
    - systems programming