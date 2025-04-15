#include "Span.hpp"

Span::Span(unsigned int n) : n(n), std::vector(new std::vector<int>[n]()){}

Span::~Span() {
	delete [] std::vector;
}

Span::Span(const Span &src){
	std::cout << "Copy constructor is called." << std::endl;
	*this = src;
}

Span &Span::operator=(const Span &other) {
	std::cout << "Assignation operator is called." << std::endl;

	if (this == &other) return *this;

	delete [] std::vector;

	std::vector<int> *temp = new std::vector<int>[other.std::vector->size()];
	std::copy(other.std::vector->begin(), other.std::vector->end(), std::back_inserter(*temp));

	n = other.n;
	std::vector = temp;
	return *this;
}

void Span::addNumber(int number) {
	if (n == 0)
		throw (LimitReached());
	
	std::vector->push_back(number);
	n -= 1;
}

unsigned int Span::longestSpan() {
	if (std::vector->size() <= 1)
		throw (NoSpanToBeFound());

	std::vector<int> newVector(std::vector->size(), 0);
	std::adjacent_difference(std::vector->begin(), std::vector->end(), newVector.begin());

	std::vector<int>::iterator iter;
	for (iter = newVector.begin(); iter != newVector.end(); ++iter)
		*iter = std::abs(*iter);

	return (*std::max_element(newVector.begin() + 1, newVector.end()));
}

unsigned int Span::shortestSpan() {
	if (std::vector->size() <= 1)
		throw (NoSpanToBeFound());

	std::vector<int> newVector(std::vector->size(), 0);
	std::adjacent_difference(std::vector->begin(), std::vector->end(), newVector.begin());

	std::vector<int>::iterator iter;
	for (iter = newVector.begin(); iter != newVector.end(); ++iter)
		*iter = std::abs(*iter);

	return (*std::min_element(newVector.begin() + 1, newVector.end()));
}

void Span::seed(unsigned int n) {

	if (n > n || n == 0)
		throw (LimitReached());
		
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++)
		std::back_inserter(*std::vector) = rand() % 1000;
	n -= n;
}