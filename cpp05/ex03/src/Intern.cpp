#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cctype>
#include <csignal>
#include <typeinfo>
#include <iostream>

Intern::Intern()
{
  std::cout << "Intern default constructor called\n";
}

Intern::Intern(Intern& intern)
{
  (void)intern;
  std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator=(const Intern& intern)
{
  (void)intern;
  std::cout << "Intern assignement operator called\n";
  return (*this);
}

Intern::~Intern()
{
  std::cout << "Intern destructor called\n";
}

const char* Intern::FormNotFoundExcept::what() const throw()
{
  return ("Form not found\n");
}

std::string unmangle(const std::string& mangled)
{
  size_t pos(0);
  while (pos <= mangled.length() && std::isdigit(mangled[pos]))
    pos++;
  return (mangled.substr(pos));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
  AForm *form[3] = {new ShrubberyCreationForm(target)
    , new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
  int i(0);
  while (i <= 2)
  {
    std::string className(typeid(*form[i]).name());
    className = unmangle(className);
    if (className == name)
      break;
    i++;
  }
  if (i > 2)
    throw (FormNotFoundExcept());
  for (int j = 0; j <= 2; j++)
  {
    if (j != i)
      delete (form[j]);
  }
  return (form[i]);
}
