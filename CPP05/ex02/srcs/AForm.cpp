#include "AForm.hpp"

AForm::AForm() : _name("default"), _target("default"), _is_signed(false), _sign_grade(1), _exec_grade(1)
{}

AForm::AForm(std::string name, std::string target, int sign_grade, int exec_grade) : _name(name), _target(target), _is_signed(false)
{
	try
	{
		if (sign_grade < 1 || exec_grade < 1 )
			throw AForm::GradeTooHighException();
		if (sign_grade > 150 || exec_grade > 150 )
			throw AForm::GradeTooLowException();
		_sign_grade = sign_grade;
		_exec_grade = exec_grade;
		std::cout << "Fields Constructor called of AForm" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

AForm::AForm(const AForm &copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of AForm" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Destructor called of AForm" << std::endl;
}

AForm & AForm::operator=(const AForm &assign)
{
	_name = assign.get_name();
	_is_signed = assign.get_is_signed();
	_sign_grade = assign.get_sign_grade();
	_exec_grade = assign.get_exec_grade();
	return *this;
}

std::string AForm::get_name() const
{
	return _name;
}

std::string AForm::get_target() const
{
	return _target;
}

bool AForm::get_is_signed() const
{
	return _is_signed;
}

int AForm::get_sign_grade() const
{
	return _sign_grade;
}

int AForm::get_exec_grade() const
{
	return _exec_grade;
}

void AForm::beSigned(Bureaucrat &buro)
{
	if (buro.get_grade() > _sign_grade)
		throw (AForm::GradeTooLowException());
	_is_signed = true;
	std::cout << buro.get_name() << " successfully signed" << _name << std::endl;
}

void AForm::execute(Bureaucrat &buro)
{
	if (!_is_signed)
		throw (AForm::NotSigned());
	if (buro.get_grade() > _exec_grade)
		throw (AForm::GradeTooLowException());
	this->executeAction();
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	return out << "AForm: " << form.get_name() << "(name), " << form.get_is_signed() << "(is singed), " << form.get_sign_grade() << "(signed grade), " << form.get_exec_grade() << "(exec grade)." ;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char * AForm::NotSigned::what() const throw()
{
	return "Form not signed!";
}

