#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
  try
  {
    Bureaucrat Michel("Michel", 149);
    Bureaucrat Laure("Laure", 1);
    Form       Alternance("Alternance", 145, 10);
    Form       Stage("Stage", 3, 2);
    Michel.signForm(Alternance);
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.increaseGrade();
    Michel.signForm(Alternance);
    Laure.signForm(Stage);
    std::cout << Michel;
    std::cout << Laure;
    std::cout << Alternance;
    std::cout << Stage;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }
  return 0;
}
