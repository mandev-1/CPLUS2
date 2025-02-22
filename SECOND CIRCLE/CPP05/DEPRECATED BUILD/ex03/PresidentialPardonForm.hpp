#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		void	action() const;
		PresidentialPardonForm(const std::string gName);
		PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void execute(Bureaucrat const & executor) const;
        ~PresidentialPardonForm();
};