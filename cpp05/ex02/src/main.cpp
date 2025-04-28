#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>

int main()
{
  try
  {
    Bureaucrat Michel("Michel", 149);
    Bureaucrat Laure("Laure", 1);
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    std::cout << Michel;
    std::cout << Laure;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }
  return 0;
}
