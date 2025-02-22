#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

// Forward declaration of Bureaucrat
class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeRequiredSign;
        const int           _gradeRequiredExecute;

    public:
        AForm(const std::string &name, int gradeSign, int gradeExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool isSigned() const;
        int getGradeRequiredSign() const;
        int getGradeRequiredExecute() const;

        // Exception classes
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

        // Member function to sign the AForm using a Bureaucrat.
        // If the bureaucrat's grade is too low, throw a GradeTooLowException.
        void beSigned(const Bureaucrat &bureaucrat);

        //New function, which is in subject for this excercise. Making it pure virtual makes this an Abstract Function
        virtual void execute(const Bureaucrat &executor) const = 0;
        virtual void action() const = 0;
};

// Overload of insertion operator for printing AForm inAFormation
std::ostream &operator<<(std::ostream &out, const AForm &AForm);
