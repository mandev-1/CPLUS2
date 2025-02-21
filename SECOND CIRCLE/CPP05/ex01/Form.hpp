#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

// Forward declaration of Bureaucrat
class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeRequiredSign;
    const int _gradeRequiredExecute;
    
public:
    // Canonical form: Constructor, Copy constructor, Assignment operator, Destructor
    Form(const std::string &name, int gradeSign, int gradeExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getGradeRequiredSign() const;
    int getGradeRequiredExecute() const;

    // Exception classes
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

    // Member function to sign the form using a Bureaucrat.
    // If the bureaucrat's grade is too low, throw a GradeTooLowException.
    void beSigned(const Bureaucrat &bureaucrat);
};

// Overload of insertion operator for printing Form information
std::ostream &operator<<(std::ostream &out, const Form &form);
