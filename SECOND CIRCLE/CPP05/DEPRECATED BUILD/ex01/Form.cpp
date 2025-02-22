#include "Form.hpp"

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string & name, int gradeSign, int gradeExecute)
:
    _name(name),
    _isSigned(false),
    _gradeRequiredSign(gradeSign),
    _gradeRequiredExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
    {
        throw GradeTooHighException();
    }
    if (gradeSign > 150 || gradeExecute > 150)
    {
        throw GradeTooLowException();
    }
}

Form::Form(const Form & other)
:
    _name(other._name),
    _isSigned(other._isSigned),
    _gradeRequiredSign(other._gradeRequiredSign),
    _gradeRequiredExecute(other._gradeRequiredExecute)
{
    std::cout << "Copying.." << std::endl;
}

Form & Form::operator=(const Form & other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getGradeRequiredSign() const
{
    return _gradeRequiredSign;
}

int Form::getGradeRequiredExecute() const
{
    return _gradeRequiredExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade too low";
}

void Form::beSigned(const Bureaucrat & signee)
{
    if (signee.getGrade() > _gradeRequiredSign)
    {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream & operator<<(std::ostream & out, const Form & form)
{
    out << "Form: " << form.getName() << ", signed: " << std::boolalpha << form.isSigned() << ", grade required to sign: " << form.getGradeRequiredSign() << ", grade required to execute: " << form.getGradeRequiredExecute();
    return out;
}