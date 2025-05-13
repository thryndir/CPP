#include "Array.hpp"
#include <iostream>
#include <stdexcept>

template<typename T>
Array<T>::Array()
  :mArray(NULL)
  ,mLength(0)
{
  std::cout << "array default constructor called\n";
}

template<typename T>
Array<T>::Array(unsigned int n)
  :mArray(new T[n])
  ,mLength(n)
{
  std::cout << "array constructor called\n";
}

template<typename T>
Array<T>::Array(const Array<T>& array)
  :mArray(new T[array.mLength])
  ,mLength(array.mLength)
{
  std::cout << "array copy constructor called\n";
  for (unsigned int i = 0; i < mLength; i++)
  {
    mArray[i] = array.mArray[i];
  }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& array)
{
  std::cout << "array copy operator called\n";
  if (this == &array)
    return (*this);
  delete[] mArray;
  mArray = new T[array.mLength];
  mLength = array.mLength;
  for (unsigned int i = 0; i < mLength; i++)
    mArray[i] = array[i];
  return (*this);
}

template <typename T>
Array<T>::~Array()
{
  std::cout << "array destructor called\n";
  delete[] mArray;
}

template <typename T>
unsigned int Array<T>::size(void)
{
  return (mLength);
}

template <typename T>
T& Array<T>::operator[](unsigned int n) const
{
  if (n < 0 || n >= mLength)
    throw (std::runtime_error("index out of bounds\n"));
  return mArray[n];
}

template <typename T>
void Array<T>::print(const std::string& name) const
{
  for (unsigned int i = 0; i < mLength; i++)
    std::cout << name << " " << mArray[i] << std::endl;
}
