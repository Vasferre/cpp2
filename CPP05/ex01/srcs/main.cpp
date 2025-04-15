#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat Vasco("Vasco", 15);
	std::cout << std::endl;

	Form lowSign("Sign to low", -1, 1);
	Form lowExec("Exec to low", 1, -1);
	Form highSign("Sing to high", 151, 1);
	Form hignExec("Exec to high", 1, 1000);
	std::cout << std::endl;

	Form buroToLow("Buro to low", 12, 1);
	Vasco.signForm(buroToLow);
	std::cout << std::endl;

	Form signebleForm("Buro can sign this one!", 17, 1);
	Vasco.signForm(signebleForm);

	std::cout << std::endl;

	std::cout << signebleForm << std::endl;
	return 0;
}