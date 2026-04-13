# fma

#math/misc
## Prototype

```c
#include <math.h>

double fma(double x, double y, double z);
```

## Description

Computes a **fused multiply-add** operation:

[  
fma(x, y, z) = (x \times y) + z  
]

It performs the multiplication and addition in a **single step with only one rounding**, improving precision.

## Parameters

- `x`: First multiplier
    
- `y`: Second multiplier
    
- `z`: Value to add
    

## Return Value

- Returns ( (x \times y) + z ) with higher precision than separate operations
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 2.0;
    double y = 3.0;
    double z = 4.0;

    double result = fma(x, y, z);

    printf("fma(2, 3, 4) = %f\n", result);
    return (0);
}
```

## Notes

- Equivalent to:
    

```c
(x * y) + z
```

BUT with better precision:

- normal version may round twice
    
- `fma` rounds only once
    
- Why it matters:
    

```c
(x * y) + z   // can lose precision
fma(x, y, z)  // more accurate
```

- Special cases:
    
    - follows IEEE-754 rules strictly
        
    - handles overflow/underflow more accurately
        
- Common use cases:
    
    - graphics computations
        
    - physics simulations
        
    - numerical algorithms requiring precision