#ifndef ARRAY_HPP
#define ARRAY_HPP

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
