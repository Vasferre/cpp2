#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm 
{
	private:
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);

		void executeAction() const;
};