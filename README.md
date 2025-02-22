# C++ Projects at 42

## 📋 Overview

This repository contains C++ projects from the 42 curriculum, designed to teach fundamental programming concepts through hands-on exercises.

## 📚 Project List

### 1. (C++00)[FIRST CIRCLE/: Introduction
- Basic C++ syntax and structure
- Focus: variables, data types, control structures, functions
- Perfect for beginners starting with C++

### 2. [C++01: Zombie Project](FIRST%20CIRCLE/c%2B%2B01)
- First steps with classes and objects
- Core concepts: constructors, destructors, member functions
- Introduction to dynamic memory allocation

### 3. [C++02: Advanced Class Concepts](FIRST%20CIRCLE/c%2B%2B02)
- Ad-hoc polymorphism
- Operator overloading
- Orthodox Canonical Form implementation

### 4. [C++03: Inheritance Basics](FIRST%20CIRCLE/c%2B%2B03)
- Class hierarchies
- Base and derived classes
- Virtual functions and inheritance patterns

### 5. [C++04: Abstract Programming](FIRST%20CIRCLE/c%2B%2B04)
- Abstract classes
- Interfaces
- Pure virtual functions

## 🎯 Learning Objectives

Students will master:
- Object-oriented programming fundamentals
- Memory management
- File operations
- Exception handling
- Advanced programming techniques

## 💡 Key Skills Developed

1. Class and object management
2. Dynamic memory allocation
3. Pointer and reference usage
4. File I/O operations
5. Exception handling
6. Function pointers
7. Inheritance and polymorphism
8. Abstract class implementation

## 🚀 Expected Outcomes

After completing these projects, students will be able to:
- Write professional C++ code
- Design object-oriented systems
- Manage memory effectively
- Handle complex data structures
- Create robust and maintainable applications

Each project builds upon previous concepts, creating a comprehensive learning path in modern C++ programming.


------

## 📚 Module Summaries

### [C++ 05: Exceptions (And Repetition...)](SECOND%20CIRCLE/CPP05)
- Introduction to exception handling
- Try-catch blocks
- Custom exception classes
- Stack unwinding
###### Stack Unwinding Process

When an exception is thrown, instead of abruptly terminating the program, the runtime performs **stack unwinding**. This process involves:

- **Cleanup of Local Resources**  
    As the stack is "unwound," destructors for automatic (local) objects are invoked in the reverse order of their creation. This ensures that any allocated resources—such as memory, file handles, or network connections—are properly released.

- **Safe Exit of Functions**  
    Each function that is removed from the call stack gets an opportunity to clean up its state. This mechanism helps maintain program stability even when unexpected errors occur.

- **Error Propagation**  
    The exception travels up the call stack until it is caught by an appropriate handler, allowing the program to either recover or terminate gracefully.
- Best practices for exception safety
- [Inheritance Initialization](SECOND%20CIRCLE/CPP05/ShrubberyCreationForm.cpp)
```cpp
// When making a new ShrubberyCreationForm("garden"):

ShrubberyCreationForm::ShrubberyCreationForm(const std::string gName)
    : AForm("ShrubberyCreationForm", 145, 137),  // 1️⃣ Build parent first!
      _target(gName)                             // 2️⃣ Then add our piece
{}

```
```cpp
// WRONG WAY ❌
PresidentialPardonForm::PresidentialPardonForm(const std::string gName) 
    : AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = gName;  // Assignment after construction
}

// CORRECT WAY ✅
PresidentialPardonForm::PresidentialPardonForm(const std::string gName) 
    : AForm("PresidentialPardonForm", 25, 5),  // Initialize parent
      _target(gName)                           // Initialize member
{
}
```

### [C++ 06: Type Casting](SECOND%20CIRCLE/CPP06)
- Static cast
- Dynamic cast
- Reinterpret cast
- Const cast
- Type conversion operators
- Explicit keyword usage

### [C++ 07: Templates](SECOND%20CIRCLE/CPP07)
- Function templates
- Class templates
- Template specialization
- Template metaprogramming basics
- STL container usage
- Template parameter deduction

### [C++ 08: STL Containers](SECOND%20CIRCLE/CPP08)
- Sequential containers (vector, list, deque)
- Associative containers (map, set)
- Container adaptors (stack, queue)
- Iterators and algorithms
- STL utility functions

### [C++ 09: STL-2](SECOND%20CIRCLE/CPP09)
- Advanced algorithm usage
- Function objects (functors)
- Lambda expressions
- STL iterators in depth
- Container operations
- Performance considerations