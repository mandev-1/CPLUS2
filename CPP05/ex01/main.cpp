#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat mike;

    Bureaucrat* carl = new Bureaucrat("carl", 42);
    std::cout << carl << std::endl;
    delete carl;
    try
    {
        mike.decrementGrade();
    }
    catch (const std::exception& e) // Specify the exception type -- In C++, you need to specify the type of exception you are catching.
    {
        std::cout << "oopsie: " << e.what() << std::endl;
    }


    return EXIT_SUCCESS;
}