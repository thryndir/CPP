#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

void  Harl::debug(void)
{
  std::cout << "this is a debug" << std::endl;
}

void  Harl::info(void)
{
  std::cout << "this is an info" << std::endl;
}

void  Harl::warning(void)
{
  std::cout << "this is a warning" << std::endl;
}

void  Harl::error(void)
{
  std::cout << "this is an error" << std::endl;
}

void  Harl::complain(std::string level)
{
  void  (Harl::*funcPtr[4])(void) = {&Harl::debug, &Harl::info,
     &Harl::warning, &Harl::error};
   int indexLevel = std::atoi(level.c_str());
   (this->*funcPtr[indexLevel])();
}
