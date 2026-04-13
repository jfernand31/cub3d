# remquo

#math/rounding
## Prototype

```c
#include <math.h>

double remquo(double x, double y, int *quo);
```

## Description

Computes the **IEEE floating-point remainder** of `x / y`, similar to `remainder`, but also stores part of the **quotient** used in the calculation.

It calculates:  
[  
x - (n \times y)  
]  
where `n` is the integer quotient used internally (rounded to nearest, ties to even).

The value of `n` (or a portion of it) is stored in `*quo`.

## Parameters

- `x`: Dividend
    
- `y`: Divisor (must not be 0)
    
- `quo`: Pointer to an `int` where part of the quotient is stored
    

## Return Value

- Returns the remainder of `x / y`
    
- If `y == 0`, result is undefined
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 10.5;
    double y = 3.0;
    int quo;

    double result = remquo(x, y, &quo);

    printf("remquo(10.5, 3.0) = %f\n", result);
    printf("quotient part = %d\n", quo);

    return (0);
}
```

## Notes

- Similar to `remainder`, but also gives quotient info:
    

|Function|Extra output|
|---|---|
|`fmod`|no|
|`remainder`|no|
|`remquo`|yes (quotient bits)|

- `quo` does NOT always store full quotient:
    
    - Only a **limited number of bits** are guaranteed (implementation-defined)
        
- Useful when:
    
    - you need remainder + division info
        
    - advanced numerical algorithms
        
    - argument reduction in trig functions
        
- Special cases:
    

```c
remquo(x, 0, &quo); // ❌ undefined
```

- Common use cases:
    
    - high-performance math libraries
        
    - trigonometric reductions
        
    - scientific computing internals