# Exercise 02: PmergeMe

> Optimal Containers: *std::vector* and *std::deque*

## Description
Create a program called `PmergeMe` that implements the merge-insert sort algorithm (Ford-Johnson algorithm) to sort positive integer sequences using at least two different containers.

## Requirements
- Turn-in directory: `ex02/`
- Files to turn in: `Makefile`, `main.cpp`, `PmergeMe.{cpp, hpp}`
- Forbidden functions: None
- Must handle at least 3000 different integers
- Must use two different containers (previous containers from exercises are forbidden)

## Program Behavior
- Accept positive integer sequence as argument
- Sort using merge-insert sort algorithm
- Display error messages on standard error when needed
- Implement separate algorithms for each container (avoid generic functions)

## Output Format
The program must display:
1. First line: Unsorted sequence
2. Second line: Sorted sequence
3. Third line: Processing time for first container
4. Fourth line: Processing time for second container

## Example Usage
```bash
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
```

## Notes
- Time measurement must be precise enough to show differences between containers
- Error handling for duplicates is implementation-dependent
- Must process both sorting and data management in time measurements
