# atanh

#math/hyperbolic
## Prototype

```c
#include <math.h>

double atanh(double x);
```

## Description

Computes the **inverse hyperbolic tangent** of `x`.

It returns the value whose hyperbolic tangent is `x`.

Mathematically:  
[  
\operatorname{atanh}(x) = \frac{1}{2} \ln\left(\frac{1 + x}{1 - x}\right)  
]

## Parameters

- `x`: A real number in the range `(-1, 1)`
    

## Return Value

- Returns the value such that:
    

```c
tanh(result) = x
```

- Result is a real number (double)
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 0.5;
    double result = atanh(x);

    printf("atanh(0.5) = %f\n", result);
    return (0);
}
```

## Notes

- Domain restriction:
    
    - `-1 < x < 1`
        

```c
atanh(1.0);  // ❌ undefined
atanh(-1.0); // ❌ undefined
```

- Odd function:
    

```c
atanh(-x) = -atanh(x)
```

- Behavior:
    
    - grows very large as `x → 1`
        
    - goes to negative infinity as `x → -1`
        
- Common use cases:
    
    - statistics (logit transforms)
        
    - neural networks
        
    - numerical analysis