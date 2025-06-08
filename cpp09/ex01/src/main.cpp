#include <iostream>
#include "RPN.hpp"


int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "usage: RPN operation" << std::endl;
    return (1);
  }
  try
  {
    RPN rpn(argv[1]);
    double result = rpn.compute();
    std::cout << result << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
  return (1);
}
