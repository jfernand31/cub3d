# tanh

#math/hyperbolic
## Prototype

```c
#include <math.h>

double tanh(double x);
```

## Description

Computes the **hyperbolic tangent** of `x`.

It is the hyperbolic analogue of the tangent function.

Mathematically:  
[  
\tanh(x) = \frac{\sinh(x)}{\cosh(x)} = \frac{e^x - e^{-x}}{e^x + e^{-x}}  
]

## Parameters

- `x`: A real number (double)
    

## Return Value

- Returns the hyperbolic tangent of `x`
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1.0;
    double result = tanh(x);

    printf("tanh(1.0) = %f\n", result);
    return (0);
}
```

## Notes

- Output is always in the range:
    
    - `(-1, 1)`
        
- Odd function:
    

```c
tanh(-x) = -tanh(x)
```

- Behavior:
    
    - approaches `1` as `x → +∞`
        
    - approaches `-1` as `x → -∞`
        
- Common use cases:
    
    - neural networks (activation function)
        
    - physics (wave equations, thermodynamics)
        
    - smoothing transitions in simulations