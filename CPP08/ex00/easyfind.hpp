#progma once

#include <iostream>
#include <algorithm>

template <Typename T>
int easyfind(T const &container, int cd)
{
        typename T::const_iterator index = std::find(container.begin(), container.end(), cd)
    return (index  != container.end() ? *index : -1);
}