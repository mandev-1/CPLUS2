#include "Bureaucrat.hpp"

// Private member function
void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << "setting grade to " << grade << std::endl;
}

// Constructors
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{

}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) 
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    std::cout << "Creating a bureaucrat with the name " << _name << " and grade " << grade << std::endl;
    setGrade(grade);
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other) {
        // Can't assign _name as it's const
        _grade = other._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor [Bureaucrat]" << std::endl;
}

// Getters
std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

// Grade modification methods
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    setGrade(_grade + 1);
    std::cout << "Blud got promoted" << std::endl;
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    setGrade(_grade - 1);
    std::cout << "This is a demotion if I ever saw one" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName()
                 << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName()
                 << " because he is stupid and also because " << e.what() << std::endl;
    }
}

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}