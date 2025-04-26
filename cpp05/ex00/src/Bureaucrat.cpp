#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
  :mName(name)
  ,mGrade(grade)
{
  if (mGrade < 1)
    throw (GradeTooLowException());
  else if (mGrade > 150)
    throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
  :mName(bureaucrat.mName)
  ,mGrade(bureaucrat.mGrade)
{
  if (mGrade < 1)
    throw (GradeTooLowException());
  else if (mGrade > 150)
    throw (GradeTooHighException());
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
  if (this == &bureaucrat)
    return (*this);
  mGrade = bureaucrat.mGrade;
  return (*this);
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "destructor called \n";
}

std::string Bureaucrat::getName(void)
{
  return (mName);
}

int Bureaucrat::getGrade(void)
{
  return (mGrade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Error: the grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Error: the grade is too low");
}

void Bureaucrat::increaseGrade()
{
  mGrade++;
  if (mGrade > 150)
    throw (GradeTooHighException());
}

void Bureaucrat::decreaseGrade()
{
  mGrade--;
  if (mGrade < 1)
    throw (GradeTooLowException());
}

std::ostream& operator<<(std::ostream& out, Bureaucrat bureaucrat)
{
  out << bureaucrat.getName() << ", bureaucrate grade " << bureaucrat.getGrade() << "\n";
  return (out);
}
