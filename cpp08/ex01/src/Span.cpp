#include "Span.hpp"
#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <algorithm>

Span::Span(int N)
  :_N(N)
{
  std::cout << "Span constructor called\n";
}

Span::Span(const Span& span)
  :_N(span._N)
{
  std::cout << "Span copy constructor called \n";
  _array = span._array;
}

Span& Span::operator=(const Span& span)
{
  std::cout << "Span assignation operator called\n";
  if (this == &span)
    return (*this);
  _N = span._N;
  _array = span._array;
  return (*this);
}

Span::~Span()
{
  std::cout << "Span destructor called\n";
}

void Span::addNumber(int number)
{
  if (_array.size() >= _N)
    throw(std::runtime_error("the array is already full\n"));
  _array.push_back(number);
}

unsigned int Span::shortestSpan(void)
{
  unsigned int minGap = std::numeric_limits<unsigned int>::max();
  if (_array.size() < 2)
    throw (std::runtime_error("shortest span cannot be found\n"));
  std::vector<int> temp = _array;
  std::sort(temp.begin(), temp.end());
  for (unsigned int i = 1; i < _array.size(); i++)
  {
    unsigned int gap = std::abs(temp[i] - temp[i - 1]);
    if (gap < minGap)
      minGap = gap;
  }
  return (minGap);
}

unsigned int Span::longestSpan(void)
{
  if (_array.size() < 2)
    throw (std::runtime_error("shortest span cannot be found\n"));
  std::vector<int> temp = _array;
  std::sort(temp.begin(), temp.end());
  return (std::abs(*temp.begin() - temp[temp.size() - 1]));
}

void Span::addSequence(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
  unsigned int range = std::distance(start, end);
  if (range + _array.size() > _N)
    throw (std::runtime_error("out of array bound\n"));
  _array.insert(_array.end(), start, end);
}

std::vector<int>& Span::getArray(void)
{
  return (_array);
}
