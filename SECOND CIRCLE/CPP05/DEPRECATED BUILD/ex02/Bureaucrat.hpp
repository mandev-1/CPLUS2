#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"



class Bureaucrat
{
    private:
        const std::string _name;
        size_t _grade;
        void setGrade(int grade);

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(int grade);
        Bureaucrat(const std::string name);
        Bureaucrat(const std::string name, int grade);

        Bureaucrat& operator=(const Bureaucrat& other);

        virtual ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        // This decreases the category - 150 is the lowest, 1 is the highest
        void decrementGrade();
        // This increases the category - 1 is the highest, 150 is the lowest
        void incrementGrade();
        void signForm(AForm& form);
		void executeForm(AForm const & form) const;


// NEW THING -- EXCEPTIONS:
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);
