#include "AForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string & name, int gradeSign, int gradeExecute)
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

AForm::AForm(const AForm & other)
:
    _name(other._name),
    _isSigned(other._isSigned),
    _gradeRequiredSign(other._gradeRequiredSign),
    _gradeRequiredExecute(other._gradeRequiredExecute)
{
    std::cout << "Copying.." << std::endl;
}

AForm & AForm::operator=(const AForm & other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeRequiredSign() const
{
    return _gradeRequiredSign;
}

int AForm::getGradeRequiredExecute() const
{
    return _gradeRequiredExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade too low";
}

void AForm::beSigned(const Bureaucrat & signee)
{
    if (signee.getGrade() > _gradeRequiredSign)
    {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream & operator<<(std::ostream & out, const AForm & AForm)
{
    out << "AForm: " << AForm.getName() << ", signed: " << std::boolalpha << AForm.isSigned() << ", grade required to sign: " << AForm.getGradeRequiredSign() << ", grade required to execute: " << AForm.getGradeRequiredExecute();
    return out;
}