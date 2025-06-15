#include <iostream>
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
    PmergeMe test(input);
    test.FordJohnson(test.getDeque(), true);
    for (size_t pos = 0; pos < test.getDeque().size(); pos++)
      std::cout << test.getDeque().at(pos) << " ";
    std::cout << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  return (1);
}
