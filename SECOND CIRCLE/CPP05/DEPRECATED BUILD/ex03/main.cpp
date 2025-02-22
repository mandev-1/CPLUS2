#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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
    std::cout << BLUE << "\n=== Testing Intern Form Creation ===" << RESET << std::endl;
    try
    {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);

        std::cout << YELLOW << "Testing valid form creation:" << RESET << std::endl;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* prf = someRandomIntern.makeForm("presidential pardon", "Criminal");
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");

        if (rrf) {
            std::cout << GREEN << "Created: " << *rrf << RESET << std::endl;
            boss.signForm(*rrf);
            rrf->execute(boss);
            delete rrf;
        }

        if (prf) {
            std::cout << GREEN << "Created: " << *prf << RESET << std::endl;
            boss.signForm(*prf);
            prf->execute(boss);
            delete prf;
        }

        if (scf) {
            std::cout << GREEN << "Created: " << *scf << RESET << std::endl;
            boss.signForm(*scf);
            scf->execute(boss);
            delete scf;
        }

        std::cout << YELLOW << "\nTesting invalid form creation:" << RESET << std::endl;
        AForm* invalid = someRandomIntern.makeForm("invalid form", "test");
        if (!invalid) {
            std::cout << GREEN << "Successfully handled invalid form request" << RESET << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "\n=== Testing Form Execution Failures ===" << RESET << std::endl;
    try {
        // Test 1: Executing unsigned form
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm unsignedForm("garden");
        std::cout << YELLOW << "Attempting to execute unsigned form..." << RESET << std::endl;
        boss.executeForm(unsignedForm);

        // Test 2: Executing with insufficient grade
        Bureaucrat intern("Intern", 150);
        ShrubberyCreationForm signedForm("park");
        boss.signForm(signedForm); // Sign it with boss first
        std::cout << YELLOW << "Attempting to execute with low-grade bureaucrat..." << RESET << std::endl;
        intern.executeForm(signedForm);

        // Test 3: Testing all form types with low-grade bureaucrat
        PresidentialPardonForm pardon("Criminal");
        RobotomyRequestForm robotomy("Bender");
        boss.signForm(pardon);
        boss.signForm(robotomy);
        
        std::cout << YELLOW << "Attempting to execute Presidential Pardon..." << RESET << std::endl;
        intern.executeForm(pardon);
        
        std::cout << YELLOW << "Attempting to execute Robotomy..." << RESET << std::endl;
        intern.executeForm(robotomy);
    } 
    catch (const std::exception& e) {
        std::cout << RED << "Unexpected error: " << e.what() << RESET << std::endl;
    }

    return EXIT_SUCCESS;
}
