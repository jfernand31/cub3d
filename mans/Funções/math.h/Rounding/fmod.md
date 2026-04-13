# fmod

#math/rounding
## Prototype

```c
#include <math.h>

double fmod(double x, double y);
```

## Description

Computes the **floating-point remainder** of dividing `x` by `y`.

It returns the remainder after performing:  
[  
x - (n \times y)  
]  
where `n` is the integer quotient truncated toward zero.

## Parameters

- `x`: Dividend
    
- `y`: Divisor (must not be zero)
    

## Return Value

- Returns the remainder of `x / y` as a `double`
    
- If `y == 0`, the result is undefined
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 10.5;
    double y = 3.0;

    double result = fmod(x, y);

    printf("fmod(10.5, 3.0) = %f\n", result);
    return (0);
}
```

## Notes

- Difference from `%` operator:
    
    - `%` works only with integers
        
    - `fmod()` works with floating-point numbers
        

```c
fmod(10.5, 3.0) = 1.5
```

- Sign follows the dividend (`x`):
    

```c
fmod(-10.5, 3.0) = -1.5
```

- Related functions:
    
    - `remainder()` → IEEE-style remainder
        
    - `modf()` → splits integer and fractional parts
        
- Common use cases:
    
    - periodic behavior (angles, cycles)
        
    - wrapping values (games, simulations)
        
    - signal processing