# RPN Calculator (ex01)

> Optimal Container: *std::stack*

## Overview
Create a program that evaluates Reverse Polish Notation (RPN) mathematical expressions.

# Reverse Polish Notation (RPN)

A mathematical notation where operators follow their operands, also known as postfix notation. In RPN, operators are written after their operands instead of between them (infix notation).

## Example
- Regular notation: `3 + 4`
- RPN notation: `3 4 +`

## Key Characteristics
- Eliminates need for parentheses
- Unambiguous without operator precedence rules
- Used in stack-based calculations
- Common in computer science and some calculators (especially HP)

## Evaluation Process
1. Read tokens from left to right
2. If token is a number, push to stack
3. If token is an operator, pop required operands and apply operator
4. Push result back to stack
5. Final stack value is the result

## Common Applications
- Calculator algorithms
- Expression parsing
- Stack-based programming languages

## Details
- **Program Name**: RPN
- **Files**: 
    - Makefile
    - main.cpp
    - RPN.cpp
    - RPN.hpp
- **Forbidden Functions**: None

## Requirements
1. Accept inverted Polish mathematical expressions as arguments
2. Input numbers must be less than 10 (result can exceed this limit)
3. Support operators: `+`, `-`, `/`, `*`
4. Display results on standard output
5. Show error messages on standard error
6. Must use at least one container in implementation
7. No bracket or decimal number handling required

## Usage Examples
```bash
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
```

**Note**: Containers used in previous exercises are forbidden for this task.
