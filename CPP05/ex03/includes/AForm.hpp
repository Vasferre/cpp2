#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <fstream>
#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;


class AForm
{
    private:
        std::string name;
        std::string target;
        bool is_signed;
        int grade;
        int exec_grade;
    public:
        AForm();
        AForm(const AForm &copy);
        AForm(std::string name, std::string target, int grade, int exec_grade);
        virtual ~AForm();

        AForm & operator=(const AForm &assign);

        std::string get_name() const;
        std::string get_target() const;
        bool get_is_signed() const;
        int get_sign() const;
        int get_grade() const;

        void beSigned(Bureaucrat &buro);
        void get_grade(Bureaucrat &buro);
        void execute(Bureaucrat &buro);

        virtual void executeAction() const = 0;

        class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
        class NotSigned : public std::exception {
            virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif