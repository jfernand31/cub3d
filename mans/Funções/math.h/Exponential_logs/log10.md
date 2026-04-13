# log10

#math/exponential
## Prototype

```c
#include <math.h>

double log10(double x);
```

## Description

Computes the **base-10 logarithm** of `x`.

Mathematically:  
[  
\log_{10}(x)  
]

## Parameters

- `x`: A positive real number
    

## Return Value

- Returns the logarithm base 10 of `x`
    
- If `x ≤ 0`, the result is undefined (domain error)
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1000.0;
    double result = log10(x);

    printf("log10(1000) = %f\n", result);
    return (0);
}
```

## Notes

- Domain restriction:
    

```c
log10(0);   // ❌ -inf (error)
log10(-5);  // ❌ undefined
```

- Special values:
    

```c
log10(1) = 0
log10(10) = 1
log10(1000) = 3
```

- Relationship:
    

```c
log10(x) = log(x) / log(10)
```

- Common use cases:
    
    - scientific notation
        
    - signal processing (decibels)
        
    - magnitude scales (earthquakes, sound)