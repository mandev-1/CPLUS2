#pragma once
#include <iostream>
#include "AForm.hpp"

class Intern
{
    private:
        // Function pointer type for form creation
        typedef AForm* (Intern::*FormCreator)(std::string const &) const;

        AForm* createPresidentialForm(std::string const & target) const;
        AForm* createRobotomyForm(std::string const & target) const;
        AForm* createShrubberyForm(std::string const & target) const;
        
        // Structure to hold form types and their creators
        struct FormType
        {
            std::string name;
            FormCreator creator;
        };

        // Static member to hold the form types array
        static const FormType formTypes[];

    public:
        Intern();
        ~Intern();
        Intern(Intern const & obj);
        Intern & operator=(Intern const & rhs);

        AForm* makeForm(std::string const & formName, std::string const & target);
};

// So here we use some funky *** to save me some coding in the .cpp file:
//
// typedef AForm*              // 1. Return type - pointer to AForm class
//        (Intern::           // 2. Scope - member function of Intern class
//        *FormCreator)       // 3. New type name with pointer symbol
//        (std::string const &) // 4. Parameter type - const reference to string
//        const;              // 5. Method qualifier - const member function
//
// this allows me to have a simple structure, as I have predefined the FormCreator function using the typedef
// If I didnt do this, I would have to do this:
//      struct FormType
//      {
//         std::string name;
//         AForm* (Intern::*creator)(std::string const &) const;
//      };
//
//
// And then this:
//
// const Intern::FormType Intern::formTypes[] =
// {
//     {"presidential pardon", &Intern::createPresidentialForm},
//     {"robotomy request", &Intern::createRobotomyForm},
//     {"shrubbery creation", &Intern::createShrubberyForm}
// };