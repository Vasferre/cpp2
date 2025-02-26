#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string.h>
#include <iostream>

class Form
{
    private:
        std::string name;
        bool is_signed;
        const int grade;
        const int exec_grade;
    public:
        Form();
        Form(const Form &copy);
        Form(std::string name, int grade, int exec_grade);
        ~Form();

        Form & operator=(const Form &assign);

        std::string get_name() const;
        bool get_is_signed() const;
        int get_sign() const;
        int get_grade() const;

        void beSigned(Bureaucrat &buro);

        class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif