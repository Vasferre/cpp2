#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int n;
    public:
        Array<T>() : array(), n(0)
        {
            std::cout << "Default constructor called" << std::endl;
        }

        Array<T>(unsigned int n) : array(new T[n]), n(n)
        {
            std::cout << "Field constructor called" << std::endl;
        }

        ~Array<T>()
        {
            if (this->array)
                delete[] array;
            std::cout << "Destructor is called" << std::endl;
        }

        Array<T>(const Array<T> &other) : array(new T[other.size()]), n(other.size())
        {
            for (unsigned int i = 0; i < other.size(); i++)
                array[i] = other[i];
            std::cout << "copy constructor called" << std::endl;
        }

        T &operator[](unsigned int i) const
        {
            if (i >= this->size())
                throw OutOfBounds();
            return this->array[i];
        }

        T &operator=(const Array<T> &assign)
        {
            if (n > 0)
                delete[] array;
            array = NULL;

            array = new T[assign.size()];
            for (unsigned int i = 0; i <assign.size(); i++)
                array[i] = assign[i];
            return *this;
        }
        
        unsigned int size() const
        {
            return n;
        }

        class OutOfBounds : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Out Of Bounds";
                }
        };
};

#endif