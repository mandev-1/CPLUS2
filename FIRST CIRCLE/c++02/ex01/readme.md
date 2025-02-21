# Fixed Point Number Class - Exercise 01

## Objective
Enhance the fixed-point number class to support various numeric representations and conversions.

## Requirements

### Files to Submit
- `Makefile`
- `main.cpp`
- `Fixed.h` or `Fixed.hpp`
- `Fixed.cpp`

### Allowed Functions
- `roundf` (from `<cmath>`)

## Implementation Details

### New Constructors
1. Integer constructor:
    - Takes a constant integer parameter
    - Converts to fixed-point value
    - Fractional bits: 8

2. Float constructor:
    - Takes a constant floating-point parameter
    - Converts to fixed-point value
    - Fractional bits: 8

### Member Functions
- `float toFloat(void) const`: Converts fixed-point to float
- `int toInt(void) const`: Converts fixed-point to integer
- Operator overload: `<<` for output stream representation

## Example Usage

```cpp
int main(void) {
     Fixed a;
     Fixed const b(10);
     Fixed const c(42.42f);
     Fixed const d(b);
     
     a = Fixed(1234.4321f);
     
     std::cout << "a is " << a << std::endl;
     std::cout << "b is " << b << std::endl;
     std::cout << "c is " << c << std::endl;
     std::cout << "d is " << d << std::endl;
     
     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
     std::cout << "d is " << d.toInt() << " as integer" << std::endl;
     
     return 0;
}
```

### Expected Output
```
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
```