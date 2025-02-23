# Array Template Implementation Guide

## Why Use .tpp Files?

The `.tpp` file is commonly used for template implementations in C++ for several important reasons:

1. **Separation of Interface and Implementation**
    - Header (`.hpp`) contains declarations
    - Template implementation (`.tpp`) contains definitions
    - Helps maintain clean code organization

2. **Template Specialization**
    - Makes it easier to manage template specializations
    - Keeps specialized implementations separate from main template

3. **Build Performance**
    - Templates need to be available at compile time
    - Including implementation in header could increase compilation time
    - `.tpp` files are typically included at the end of the header

## Implementation Structure

```cpp
// Array.hpp
template <typename T>
class Array {
     // declarations
};

// Array.tpp
#include "Array.hpp"

template <typename T>
Array<T>::Array() {
     // implementation
}
```

## Best Practices

- Always include `.tpp` at the end of your header file
- Keep template definitions visible to the compiler
- Use explicit instantiation when needed

## Note

For this exercise, using a `.tpp` file is optional but recommended for better code organization and maintainability.

The exercise focuses on implementing a template array class with proper memory management and bounds checking.

## Historical Context

The use of `.tpp` files for template implementations became a common practice around 1998, coinciding with the standardization of C++98. While not officially mandated by the C++ standard, it emerged as a community-driven convention to solve template organization issues in larger codebases.

- Initially proposed in early 1990s
- Widely adopted after C++98
- Supported by major IDEs by early 2000s