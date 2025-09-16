#ifndef ARRAY_HPP
#define ARRAY_HPP


# define RED "\033[1;30m"
# define PURPLE "\033[1;31m"
# define WHITE "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;34m"
# define LIGHT_YELLOW "\033[1;35m"
# define LIGHT_GREEN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"
# define BIG "\033[1m"

#include <string>

template <typename T>
class Array
{
  private:
    T* mArray;
    unsigned int mLength;
  public:
    Array();
    Array(unsigned int n);
    Array(const Array& array);
    Array& operator=(const Array& array);
    ~Array();
    unsigned int size(void);
    T& operator[](unsigned int n) const;
    void print(const std::string& name) const;
};

#include "Array.tpp"
#endif
