#include "Span.hpp"

int main(void)
{

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		sp.addNumber(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.LongestSpan() << std::endl << std::endl;

	Span sp2 = Span(10000);
	sp2.seed(10000);

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.LongestSpan() << std::endl;

	return 0;
}