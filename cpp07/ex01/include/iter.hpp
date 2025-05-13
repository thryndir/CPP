#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void initialise(T& array)
{
  array = 8;
}

template <typename T>
void multiply(T& array)
{
  array *= 2;
}

template <typename T>
void display(T& array, const std::string& name)
{
  std::cout << name << " " << array << std::endl;
}

template <typename T>
void iter(T* array, T size, const std::string& name)
{
  for (T i = 0; i < size; i++)
  {
    display(array[i], name);
  }
}


template <typename T>
void iter(T* array, T size, void (*func)(T& array))
{
  for (T i = 0; i < size; i++)
  {
    func(array[i]);
  }
}

#endif
