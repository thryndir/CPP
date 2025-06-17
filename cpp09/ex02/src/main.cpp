#include <iostream>
#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cerr << "error: usage: ./PmergeMe 0 1 2 33 ...\n";
    return (1);
  }
  std::string input;
  for (int i = 1; argv[i]; i++)
  {
    if (i > 1)
      input += " ";
    input += argv[i];
  }
  try
  {
    clock_t parsingStart = clock();
    PmergeMe test(input);
    clock_t parsingEnd = clock();
    double parsingTime = static_cast<double>(parsingEnd - parsingStart) / CLOCKS_PER_SEC * 1000000.0;
    clock_t vectorStart = clock();
    test.FordJohnson(test.getVector(), true);
    clock_t vectorEnd = clock();
    clock_t dequeStart= clock();
    test.FordJohnson(test.getDeque(), true);
    clock_t dequeEnd = clock();
    double vectorTime = static_cast<double>(vectorEnd - vectorStart)
                         / CLOCKS_PER_SEC * 1000000.0 + parsingTime;
    double dequeTime = static_cast<double>(dequeEnd - dequeStart)
                        / CLOCKS_PER_SEC * 1000000.0 + parsingTime;
    std::cout << "Before: " << input << std::endl;
    std::cout << "After: " << test.getVector() << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of "
     << test.getVector().size() << " elements with std::vector : " << vectorTime << " us"<< std::endl;
    std::cout << "Time to process a range of "
     << test.getDeque().size() << " elements with std::deque : " << dequeTime << " us" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  return (1);
}
