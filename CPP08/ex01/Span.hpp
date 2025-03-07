#progma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>

class Span 
{
    private:
        unsigned int n;
        std::vector<int> *vector;
    public:
        Span(unsigend int n = 0);
        ~Span();
        Span(Span const & src);
        Span & operator=(Span const & rhs);

        void    addNumber(int);
        unsigned int    shortestSpan();
        unsigned int    LongestSpan();

        void    seed(unsigned int);
        
        class LimitReached: public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return "Limit reached";
            }
        };

        class NoSpanToBeFound: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "No span can be found";
                }
        };
};