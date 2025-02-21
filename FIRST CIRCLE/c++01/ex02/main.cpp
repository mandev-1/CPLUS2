#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    // Printing memory addresses
    std::cout << "Memory addresses:" << std::endl;
    std::cout << "str address:\t" << &str << std::endl;
    std::cout << "stringPTR:\t" << stringPTR << std::endl;
    std::cout << "stringREF:\t" << &stringREF << std::endl;

    // Printing values
    std::cout << "\nValues:" << std::endl;
    std::cout << "str:\t\t" << str << std::endl;
    std::cout << "stringPTR:\t" << *stringPTR << std::endl;
    std::cout << "stringREF:\t" << stringREF << std::endl;

    return 0;
}

// This program demonstrates the relationship between pointers and references in C++. Here's what's happening:

// 1. We create a string variable `str` with the value "HI THIS IS BRAIN"
// 2. We create a pointer `stringPTR` that points to `str`
// 3. We create a reference `stringREF` that references `str`

// The program then prints:
// 1. The memory addresses of:
//    - The original string
//    - The pointer
//    - The reference
// 2. The values of:
//    - The original string
//    - The value pointed to by the pointer
//    - The value referenced by the reference

// When you run this program, you'll see that:
// - All three memory addresses are the same (because they all refer to the same location in memory)
// - All three values are the same (because they're all accessing the same string)

// The key difference between pointers and references is that:
// - References must be initialized when declared
// - References cannot be null
// - References cannot be reassigned to refer to a different variable
// - References provide a cleaner syntax when accessing values (no dereferencing operator * needed)
