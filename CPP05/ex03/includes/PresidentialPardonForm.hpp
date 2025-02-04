#include <ctime>
#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);

        void executeAction() const;
};