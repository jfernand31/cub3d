# log

#math/exponential
## Prototype

```c
#include <math.h>

double log(double x);
```

## Description

Computes the **natural logarithm** of `x`, i.e. logarithm base ( e ).

Mathematically:  
[  
\log(x) = \ln(x)  
]

## Parameters

- `x`: A positive real number
    

## Return Value

- Returns the natural logarithm of `x`
    
- If `x ≤ 0`, the result is undefined (domain error)
    

## Example

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 2.718281828;
    double result = log(x);

    printf("log(x) = %f\n", result);
    return (0);
}
```

## Notes

- Domain restriction:
    

```c
log(0);   // ❌ -inf (error)
log(-1);  // ❌ undefined
```

- Special values:
    

```c
log(1) = 0
log(e) = 1
```

- Relationship:
    

```c
log(x) = ln(x)
```

- Change of base formula:
    

```c
log_b(x) = log(x) / log(b)
```

- Common use cases:
    
    - exponential growth/decay inversion
        
    - statistics and probability
        
    - complexity analysis (Big-O)