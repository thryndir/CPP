#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "error: use: ./convert arg\n";
    return (1);
  }
  ScalarConvert::convert(argv[1]);
}
