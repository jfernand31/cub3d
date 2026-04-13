# log2

#math/exponential
## Prototype

```c
#include <math.h>

double log2(double x);
```

## Description

Computes the **base-2 logarithm** of `x`.

Mathematically:  
[  
\log_{2}(x)  
]

## Parameters

- `x`: A positive real number
    

## Return Value

- Returns the logarithm base 2 of `x`
    
- If `x ≤ 0`, the result is undefined (domain error)
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 8.0;
    double result = log2(x);

    printf("log2(8) = %f\n", result);
    return (0);
}
```

## Notes

- Domain restriction:
    

```c
log2(0);   // ❌ -inf (error)
log2(-1);  // ❌ undefined
```

- Special values:
    

```c
log2(1) = 0
log2(2) = 1
log2(16) = 4
```

- Relationship:
    

```c
log2(x) = log(x) / log(2)
```

- Common use cases:
    
    - computer science (binary systems)
        
    - algorithm complexity (O(log n))
        
    - memory and data sizing