#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Define the static lookup table
const Intern::FormType Intern::formTypes[] = {
    {"presidential pardon", &Intern::createPresidentialForm},
    {"robotomy request", &Intern::createRobotomyForm},
    {"shrubbery creation", &Intern::createShrubberyForm}
};

// Constructor implementations
Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(Intern const & obj) { (void)obj; }
Intern & Intern::operator=(Intern const & rhs) { (void)rhs; return *this; }

// Private form creation methods
AForm* Intern::createPresidentialForm(std::string const & target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyForm(std::string const & target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyForm(std::string const & target) const {
    return new ShrubberyCreationForm(target);
}

// Main makeForm method
AForm* Intern::makeForm(std::string const & formName, std::string const & target) {
    for (int i = 0; i < 3; i++) {
        if (formTypes[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formTypes[i].creator)(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    return NULL;
}