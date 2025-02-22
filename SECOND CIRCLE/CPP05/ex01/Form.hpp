#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

// Forward declaration of Bureaucrat
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeRequiredSign;
        const int _gradeRequiredExecute;
        
    public:
        Form(const std::string &name, int gradeSign, int gradeExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        std::string getName() const;
        bool isSigned() const;
        int getGradeRequiredSign() const;
        int getGradeRequiredExecute() const;
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        void beSigned(const Bureaucrat &bureaucrat);
};

// Overload of insertion operator for printing Form information
std::ostream &operator<<(std::ostream &out, const Form &form);
