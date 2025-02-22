#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.

ShrubberyCreationForm::ShrubberyCreationForm(const std::string gName)    // Constructor taking target name
    : AForm("ShrubberyCreationForm", 145, 137),  // Initialize parent with (formName, signGrade, execGrade)
      _target(gName)                             // Initialize member variable with passed parameter
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::action() const
{
    std::ofstream outFile(_target + "_shrubbery");
    if (!outFile)
    {
        throw std::runtime_error("Failed to create shrubbery file");
    }
    outFile <<
    "                /\\\n"
    "               /  \\\n"
    "              /++++\\\n"
    "             /  ()  \\\n"
    "             /      \\\n"
    "            /~`~`~`~`\\\n"
    "         ---/ COOL TREE \\---\n"
    "        |  with shrubberies  |\n"
    "         ---           ---\n"
    "                ||\n"
    "                ||\n"
    "             ___||___\n"
    "            /   ||   \\\n"
    "           /__________\\\n"
    << std::endl;
    outFile.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
    AForm::execute(executor); // This will check if form is signed and executor grade
    this->action();
}