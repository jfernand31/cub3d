# modf

#math/misc
## Prototype

```c
#include <math.h>

double modf(double x, double *iptr);
```

## Description

Splits a floating-point number into its **integer part** and **fractional part**.

It separates `x` into:

- integer part → stored in `*iptr`
    
- fractional part → returned by the function
    

Mathematically:  
[  
x = \text{integer part} + \text{fractional part}  
]

## Parameters

- `x`: The floating-point number to split
    
- `iptr`: Pointer to store the integer part
    

## Return Value

- Returns the fractional part of `x`
    
- Stores the integer part in `*iptr`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 3.14159;
    double int_part;
    
    double frac_part = modf(x, &int_part);

    printf("x = %f\n", x);
    printf("integer part = %f\n", int_part);
    printf("fractional part = %f\n", frac_part);

    return (0);
}
```

## Notes

- Sign is preserved:
    

```c
modf(-3.7, &iptr);
// iptr = -3.0
// return = -0.7
```

- Relationship:
    

```c
x = integer_part + fractional_part
```

- Difference from `trunc`:
    
    - `trunc(x)` → returns integer part directly
        
    - `modf(x)` → splits into two parts
        
- Common use cases:
    
    - formatting numbers
        
    - numerical algorithms
        
    - separating whole and decimal parts in calculations