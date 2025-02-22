#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    const std::string RED = "\033[1;31m";
    const std::string GREEN = "\033[1;32m";
    const std::string YELLOW = "\033[1;33m";
    const std::string BLUE = "\033[1;34m";
    const std::string RESET = "\033[0m";
    std::cout << BLUE << "\n=== Testing ShrubberyCreationForm ===" << RESET << std::endl;
    try
    {
        Bureaucrat highRank("HighRank", 1);
        Bureaucrat lowRank("LowRank", 150);
        ShrubberyCreationForm shrub("garden");
        std::cout << YELLOW << "Attempting to execute unsigned form..." << RESET << std::endl;
        try
        {
            shrub.execute(highRank);
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Error: " << e.what() << RESET << std::endl;
        }
        std::cout << YELLOW << "Signing form..." << RESET << std::endl;
        shrub.beSigned(highRank);
        std::cout << GREEN << "Form signed successfully!" << RESET << std::endl;
        std::cout << YELLOW << "Executing with high rank..." << RESET << std::endl;
        shrub.execute(highRank);
        std::cout << GREEN << "Shrubbery created successfully!" << RESET << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "\n=== Testing RobotomyRequestForm ===" << RESET << std::endl;
    try
    {
        Bureaucrat midRank("MidRank", 45);
        RobotomyRequestForm robot("Target");
        std::cout << YELLOW << "Signing robotomy form..." << RESET << std::endl;
        robot.beSigned(midRank);
        std::cout << YELLOW << "Attempting multiple robotomies..." << RESET << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << YELLOW << "Attempt " << i + 1 << ":" << RESET << std::endl;
            robot.execute(midRank);
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "\n=== Testing PresidentialPardonForm ===" << RESET << std::endl;
    try
    {
        Bureaucrat president("President", 5);
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Criminal");
        std::cout << YELLOW << "Attempting to execute with intern..." << RESET << std::endl;
        try
        {
            pardon.execute(intern);
        }
        catch (std::exception& e)
        {
            std::cout << RED << "Error: " << e.what() << RESET << std::endl;
        }
        std::cout << YELLOW << "Signing with president..." << RESET << std::endl;
        pardon.beSigned(president);
        std::cout << GREEN << "Form signed successfully!" << RESET << std::endl;
        std::cout << YELLOW << "Executing pardon..." << RESET << std::endl;
        pardon.execute(president);
        std::cout << GREEN << "Pardon executed successfully!" << RESET << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "\n=== Testing Invalid Grade Cases ===" << RESET << std::endl;
    try
    {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Error creating invalid bureaucrat: " << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "\n=== Testing Memory Management ===" << RESET << std::endl;
    {
        AForm* form = new ShrubberyCreationForm("test");
        delete form;
    }
    return EXIT_SUCCESS;
}
