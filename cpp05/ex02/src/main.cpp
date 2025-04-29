#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
  try
  {
    ShrubberyCreationForm tree("tree");
    PresidentialPardonForm president("president");
    RobotomyRequestForm robot("robot");
    Bureaucrat Michel("Michel", 149);
    Bureaucrat Laure("Laure", 1);
    std::cout << 
    std::cout << Laure;
    std::cout << tree;
    std::cout << president;
    std::cout << robot;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }
  return 0;
}
