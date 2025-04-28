#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
  :mName(name)
  ,mGrade(grade)
{
  std::cout << "Bureaucrat " << mName << " constructor called\n";
  if (mGrade < 1)
    throw (GradeTooLowException());
  else if (mGrade > 150)
    throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
  :mName(bureaucrat.mName)
  ,mGrade(bureaucrat.mGrade)
{
  std::cout << "Bureaucrat " << mName << " copy constructor called\n";
  if (mGrade < 1)
    throw (GradeTooLowException());
  else if (mGrade > 150)
    throw (GradeTooHighException());
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
  std::cout << "Bureaucrat " << mName << " copy assignation operator called\n";
  if (this == &bureaucrat)
    return (*this);
  mGrade = bureaucrat.mGrade;
  return (*this);
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat " << mName << " destructor called\n";
}

std::string Bureaucrat::getName(void) const
{
  return (mName);
}

int Bureaucrat::getGrade(void) const
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

void Bureaucrat::decreaseGrade()
{
  mGrade++;
  if (mGrade > 150)
    throw (GradeTooHighException());
}

void Bureaucrat::increaseGrade()
{
  mGrade--;
  if (mGrade < 1)
    throw (GradeTooLowException());
}

void Bureaucrat::signForm(Form& form)
{
  try
  {
    form.beSigned(*this);
  }
  catch (const std::exception& e)
  {
    std::cout << mName << " couldn't sign " << form.getName() << " because "
      << e.what();
    return ;
  }
  std::cout << mName << " signed " << form.getName() << "\n";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
  out << bureaucrat.getName() << ", bureaucrate grade " << bureaucrat.getGrade() << "\n";
  return (out);
}
