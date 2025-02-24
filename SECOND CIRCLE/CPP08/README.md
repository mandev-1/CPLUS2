# Stuff n Things

- Using the Standard Template Library (STL) is the goal of this exercise
- So we should use them AS MUCH AS WE CAN! 
- Let's use them even when it is not required, but only possible
- Whenever appropriate basically

> TIP: Import with the `<algorithm>` header.
> The *containers* are:
> 1. vector
> 2. list
> 3. map
> ----
> 4. stack
> 5. deque
> 6. queue
> 7. priority queue*
> 8. set
> 9. multiset*
> 10. multimap*

## STL Algorithm Examples

### Find Algorithm
```cpp
// Finding element in vector
std::vector<int> numbers;
numbers.push_back(1);
numbers.push_back(2);
numbers.push_back(3);
numbers.push_back(4);
numbers.push_back(5);
std::vector<int>::iterator it = std::find(numbers.begin(), numbers.end(), 3);
if (it != numbers.end())
    std::cout << "Found: " << *it << '\n';
```

### Sort Algorithm
```cpp
// Sorting container
std::vector<int> vec;
vec.push_back(5);
vec.push_back(2);
vec.push_back(8);
vec.push_back(1);
vec.push_back(9);
std::sort(vec.begin(), vec.end());
```

### Count Algorithm
```cpp
// Counting elements
std::list<int> lst;
lst.push_back(1);
lst.push_back(2);
lst.push_back(2);
lst.push_back(3);
lst.push_back(2);
lst.push_back(4);
int count = std::count(lst.begin(), lst.end(), 2);
```

### Transform Algorithm
```cpp
// Transforming elements
std::vector<int> src;
src.push_back(1);
src.push_back(2);
src.push_back(3);
src.push_back(4);
std::vector<int> dest(4);
std::transform(src.begin(), src.end(), dest.begin(),
              std::multiplies<int>());
```

### Technical Requirements

#### Development Environment
- Use VS Code with appropriate extensions
- Utilize Git for version control
- Familiarity with Linux commands

#### Development Process
1. Review specifications thoroughly
2. Break down into modular tasks
3. Implement using STL components
4. Test and debug systematically

#### Testing & Debugging
- Use VS Code's integrated debugger
- Write unit tests where appropriate
- Verify STL implementations work as expected


---


###### Exercise 00: Easy find
In this exercise you need to implement a function template named easyfind (likely declared in easyfind.hpp) that receives a container (assumed to hold integers) and an integer, and then finds the first occurrence of that integer using STL algorithms (e.g., by including <algorithm>). If the element isn’t found, throw an exception or return an error value.

Exercise 01: Span
Here you’ll develop a Span class (declared in Span.hpp and implemented in Span.cpp). This class stores up to N integers (specified by the constructor). It provides an addNumber() member function to add numbers (throwing an exception if exceeding capacity) and two member functions: shortestSpan() and longestSpan(), which compute the minimum and maximum differences among the stored numbers. Testing with at least 10,000 numbers is recommended.