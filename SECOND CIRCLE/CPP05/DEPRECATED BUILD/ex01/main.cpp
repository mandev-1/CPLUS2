#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"

int main(void)
{
    std::cout << BLUE "\n=== Testing Basic Bureaucrat Operations ===" RESET << std::endl;
    try {
        // Test constructors
        Bureaucrat default_b;
        std::cout << &default_b << std::endl;

        Bureaucrat high("High", 1);
        std::cout << &high << std::endl;

        Bureaucrat low("Low", 150);
        std::cout << &low << std::endl;

        // Test copy constructor
        Bureaucrat copy(high);
        std::cout << "Copy of High: " << &copy << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE "\n=== Testing Grade Modifications ===" RESET << std::endl;
    try {
        Bureaucrat worker("Worker", 75);
        std::cout << "Initial state: " << &worker << std::endl;

        std::cout << YELLOW "Incrementing grade..." RESET << std::endl;
        worker.incrementGrade();
        std::cout << "After increment: " << &worker << std::endl;

        std::cout << YELLOW "Decrementing grade..." RESET << std::endl;
        worker.decrementGrade();
        std::cout << "After decrement: " << &worker << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE "\n=== Testing Grade Limits ===" RESET << std::endl;
    try {
        Bureaucrat toohigh("TooHigh", 0);
    }
    catch (const std::exception& e) {
        std::cout << GREEN "Caught expected error: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat toolow("TooLow", 151);
    }
    catch (const std::exception& e) {
        std::cout << GREEN "Caught expected error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE "\n=== Testing Form Interactions ===" RESET << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Form basicForm("Basic Form", 100, 100);

        std::cout << YELLOW "Attempting to sign with intern..." RESET << std::endl;
        try {
            basicForm.beSigned(intern);
        }
        catch (const std::exception& e) {
            std::cout << GREEN "Caught expected error: " << e.what() << RESET << std::endl;
        }

        std::cout << YELLOW "Signing with boss..." RESET << std::endl;
        basicForm.beSigned(boss);
        std::cout << "Form status: " << basicForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE "\n=== Testing Memory Management ===" RESET << std::endl;
    {
        Bureaucrat* dynamic = new Bureaucrat("Dynamic", 42);
        std::cout << dynamic << std::endl;
        delete dynamic;
    }

    return EXIT_SUCCESS;
}