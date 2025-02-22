#include <iostream>
#include <cstdlib>  // for rand(), srand()
#include <ctime>    // for time()

#include "Base.hpp"

Base* generate(void)
{
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int r = std::rand() % 3;
        switch (r) {
                case 0:
                        return new A();
                case 1:
                        return new B();
                case 2:
                default:
                        return new C();
        }
}

Base::~Base()
{
    
}

// Identify the type using a pointer.
void identify(Base* p)
{
        if (dynamic_cast<A*>(p))
                std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(p))
                std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(p))
                std::cout << "C" << std::endl;
        else
                std::cout << "Unknown type" << std::endl;
}

// Identify the type using a reference.
void identify(Base& p)
{
        try {
                (void)dynamic_cast<A&>(p);
                std::cout << "A" << std::endl;
                return;
        } catch (...) {
        }
        try {
                (void)dynamic_cast<B&>(p);
                std::cout << "B" << std::endl;
                return;
        } catch (...) {
        }
        try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                return;
        } catch (...) {
        }
        std::cout << "Unknown type" << std::endl;
}


int main()
{
    // ANSI color codes
    const std::string red     = "\033[1;31m";
    const std::string green   = "\033[1;32m";
    const std::string yellow  = "\033[1;33m";
    const std::string blue    = "\033[1;34m";
    const std::string magenta = "\033[1;35m";
    const std::string cyan    = "\033[1;36m";
    const std::string reset   = "\033[0m";

    // Random generation tests
    const int numTests = 5;
    std::cout << cyan << "=== Random Generation Tests ===" << reset << std::endl;
    for (int i = 0; i < numTests; i++)
    {
        Base* p = generate();
        std::cout << blue << "Test " << i + 1 << ":" << reset << std::endl;

        std::cout << green << "Pointer identification: " << reset;
        identify(p);
        
        std::cout << yellow << "Reference identification: " << reset;
        identify(*p);

        std::cout << std::endl;
        delete p;
    }

    // Explicit object tests for each type
    std::cout << cyan << "=== Explicit Object Tests ===" << reset << std::endl;
    {
        A a;
        std::cout << magenta << "Explicit A:" << reset << std::endl;
        std::cout << green << "Pointer identification: " << reset;
        identify(&a);
        std::cout << yellow << "Reference identification: " << reset;
        identify(a);
        std::cout << std::endl;
    }
    {
        B b;
        std::cout << magenta << "Explicit B:" << reset << std::endl;
        std::cout << green << "Pointer identification: " << reset;
        identify(&b);
        std::cout << yellow << "Reference identification: " << reset;
        identify(b);
        std::cout << std::endl;
    }
    {
        C c;
        std::cout << magenta << "Explicit C:" << reset << std::endl;
        std::cout << green << "Pointer identification: " << reset;
        identify(&c);
        std::cout << yellow << "Reference identification: " << reset;
        identify(c);
        std::cout << std::endl;
    }

    // Null pointer test (only pointer based, as reference would be unsafe)
    std::cout << cyan << "=== Null Pointer Test ===" << reset << std::endl;
    Base* nullPtr = nullptr;
    std::cout << red << "Null Pointer identification: " << reset;
    identify(nullPtr);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}