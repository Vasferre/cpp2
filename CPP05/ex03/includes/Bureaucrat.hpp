#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>

class form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        void inc();
        void dec();

        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &assign);

        std::string get_name() const;
        int get_grade() const;

        class GradeTooHighException : public std::exception
        {
        public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif