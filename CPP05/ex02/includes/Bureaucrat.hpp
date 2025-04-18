#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	void increment();
	void decrement();
	void signForm(AForm &form);
	void executeForm(AForm &form);

	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(std::string _name, int grade);
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