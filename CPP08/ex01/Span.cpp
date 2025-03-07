#include "Span.hpp"

Span::Span(unsigned int n) : n(n), vector(new std::vector<int>[n]())
{

}

Span::~Span()
{
    delete [] vector;
}

Span::Span(const Span &src)
{
    cout << "Copy constructor is called." << endl;
    *this = src;
}

Span &Span::operator=(const Span &other)
{
    cout << "Assignation operator is called" << endl;

    if (this == &other) return *this;

    delete [] vector;

    std::vector<int> *temp = new std::vector<int>[other.vector->size()];
    std::copy(other.vector->begin(), other.vector->end(), std::back_inserter(*temp));

    n = other.n;
    vector = temp;
    return *this;
}

void Span::addNumber(int number)
{
    if (n == 0)
        throw (LimitReached());
    vector->push_back(number);
    n -= 1;
}

unsigned int Span::LongestSpan()
{
    if(vector->size() <= 1)
        throw (NoSpanToBeFound());

    std::vector<int> newVector(vector->size(), 0);
    std::adjacent_difference(vector->begin(), vector->end(), newVector.begin());

    std::vector<int>::iterator iter;
    for (iter = newVector.begin(); iter != newVector.end(); ++iter)
        *iter = std::abs(*iter);

    return (*std::max_element(newVector.begin() + 1, newVector.end()));
}

unsigned int Span::shortestSpan()
{
    if(vector->size() <= 1)
        throw (NoSpanToBeFound());

    std::vector<int> newVector(vector->size(), 0);
    std::adjacent_difference(vector->begin(), vector->end(), newVector.begin());

    std::vector<int>::iterator iter;
    for (iter = newVector.begin(); iter != newVector.end(); ++iter)
        *iter = std::abs(*iter);

    return (*std::max_element(newVector.begin() + 1, newVector.end()));
}

void Span::seed(unsigned int n)
{
    if(n > n || n == 0)
        throw (LimitReached());
    srand(time(NULL));
    for (unsigned int i = 0; i < n; i++)
        std::back_inserter(*vector) = rand() % 1000;
    n -= n;
}