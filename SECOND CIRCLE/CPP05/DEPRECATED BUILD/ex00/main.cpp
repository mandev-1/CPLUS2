#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"

int main(void)
{
    std::cout << CYAN "\n=== Testing Basic Construction ===\n" RESET << std::endl;
    try
    {
        Bureaucrat basic;
        std::cout << GREEN "Default bureaucrat created successfully" RESET << std::endl;

        Bureaucrat named("John");
        std::cout << GREEN "Named bureaucrat created successfully" RESET << std::endl;

        Bureaucrat graded(75);
        std::cout << GREEN "Graded bureaucrat created successfully" RESET << std::endl;

        Bureaucrat full("Alice", 100);
        std::cout << GREEN "Fully specified bureaucrat created successfully" RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED "Construction error: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA "\n=== Testing Grade Limits ===\n" RESET << std::endl;
    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
    }
    catch (const std::exception& e)
    {
        std::cout << YELLOW "Expected error: " << e.what() << RESET << std::endl;
    }

    try
    {
        Bureaucrat tooLow("TooLow", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << YELLOW "Expected error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE "\n=== Testing Grade Modifications ===\n" RESET << std::endl;
    try
    {
        Bureaucrat worker("Worker", 75);
        std::cout << "Worker address: " << &worker << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        worker.incrementGrade();
        std::cout << "Worker address: " << &worker << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        worker.decrementGrade();
        std::cout << "Worker address: " << &worker << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED "Modification error: " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN "\n=== Testing Edge Cases ===\n" RESET << std::endl;
    try
    {
        Bureaucrat topRank("TopRank", 1);
        std::cout << "Trying to increment top rank..." << std::endl;
        topRank.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << YELLOW "Expected error: " << e.what() << RESET << std::endl;
    }

    try
    {
        Bureaucrat bottomRank("BottomRank", 150);
        std::cout << "Trying to decrement bottom rank..." << std::endl;
        bottomRank.decrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << YELLOW "Expected error: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA "\n=== Testing Copy Constructor and Assignment ===\n" RESET << std::endl;
    try
    {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "Original address: " << &original << std::endl;
        std::cout << "Copy address: " << &copy << std::endl;

        Bureaucrat assigned;
        assigned = original;
        std::cout << "Assigned address: " << &assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED "Copy/Assignment error: " << e.what() << RESET << std::endl;
    }

    return EXIT_SUCCESS;
}