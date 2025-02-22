#pragma once
#include <iostream>
#include "AForm.hpp"

class Intern
{
    private:
        // Function pointer type for form creation
        typedef AForm* (Intern::*FormCreator)(std::string const &) const;
        
        // Structure to hold form types and their creators
        struct FormType
        {
            std::string name;
            FormCreator creator;
        };

        // Private form creation methods
        AForm* createPresidentialForm(std::string const & target) const;
        AForm* createRobotomyForm(std::string const & target) const;
        AForm* createShrubberyForm(std::string const & target) const;

        // Static member to hold the form types array
        static const FormType formTypes[];

    public:
        Intern();
        ~Intern();
        Intern(Intern const & obj);
        Intern & operator=(Intern const & rhs);

        AForm* makeForm(std::string const & formName, std::string const & target);
};