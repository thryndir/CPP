#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Span.hpp"

void printVector(std::vector<int>::iterator start, std::vector<int>::iterator end, const std::string& name)
{
  std::cout << name << std::endl;
  while (start != end)
  {
    std::cout << *start << " ";
    start++;
  }
  std::cout << "\n\n\n";
}

void fillVector(std::vector<int>& vec)
{
  std::vector<int>::iterator it = vec.begin();
  while (it != vec.end())
  {
    *it = abs(rand() % 100);
    it++;
  }
}

int main( void )
{
  try
  {
    srand(time(NULL));
    Span span1(10);
    Span span2(1);
    span2.addNumber(8);
    std::vector<int> vec(10);
    fillVector(vec);
    printVector(vec.begin(), vec.end(), "vec");
    span1.addSequence(vec.begin(), vec.end());
    printVector(span1.getArray().begin(), span1.getArray().end(), "span1");
    std::cout << "longest span is: " << span1.longestSpan() << std::endl;
    std::cout << "shortest span is: " << span1.shortestSpan() << std::endl;
    std::cout << span2.longestSpan() << std::endl;
    std::cout << span2.shortestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }
  return 0;
}
