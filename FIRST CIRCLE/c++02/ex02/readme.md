# Exercise 02: Fixed-Point Number Operations

## Objective
Implement operator overloading and static member functions for a Fixed-point number class.

## Files to Submit
- `Makefile`
- `main.cpp`
- `Fixed.h` or `Fixed.hpp`
- `Fixed.cpp`

## Requirements

### 1. Operator Overloading
Implement the following operators:

#### Comparison Operators
- Greater than (`>`)
- Less than (`<`)
- Greater than or equal to (`>=`)
- Less than or equal to (`<=`)
- Equal to (`==`)
- Not equal to (`!=`)

#### Arithmetic Operators
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`) (Note: Division by 0 may crash)

#### Increment/Decrement Operators
- Pre-increment (`++x`)
- Post-increment (`x++`)
- Pre-decrement (`--x`)
- Post-decrement (`x--`)

### 2. Static Member Functions
Implement these utility functions:
- `min(Fixed&, Fixed&)` → Returns reference to smaller value
- `min(const Fixed&, const Fixed&)` → Const version
- `max(Fixed&, Fixed&)` → Returns reference to larger value
- `max(const Fixed&, const Fixed&)` → Const version

## Example Usage
```cpp
int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;             // 0
    std::cout << ++a << std::endl;           // 0.00390625
    std::cout << a << std::endl;             // 0.00390625
    std::cout << a++ << std::endl;           // 0.00390625
    std::cout << a << std::endl;             // 0.0078125
    std::cout << b << std::endl;             // 10.1016
    std::cout << Fixed::max(a, b) << std::endl; // 10.1016
    
    return 0;
}
```

Note: Only `roundf` from `<cmath>` is allowed.