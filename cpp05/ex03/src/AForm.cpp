#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string& name, int signLevel, int execLevel, bool approved)
  :mName(name)
  ,mSigned(approved)
  ,mSignLevel(signLevel)
  ,mExecLevel(execLevel)
{
  std::cout << "AForm " << mName << " constructor called\n";
  if (mSignLevel > 150 || mExecLevel > 150)
    throw (GradeTooHighException());
  else if (mSignLevel < 1 || mExecLevel < 1)
    throw (GradeTooLowException());
}

AForm::AForm(const AForm& form)
  :mName(form.mName)
  ,mSigned(form.mSigned)
  ,mSignLevel(form.mSignLevel)
  ,mExecLevel(form.mExecLevel)
{
  std::cout << "AForm " << mName << " copy constructor called\n";
  if (mSignLevel > 150 || mExecLevel > 150)
    throw (GradeTooHighException());
  else if (mSignLevel < 1 || mExecLevel < 1)
    throw (GradeTooLowException());
}

AForm& AForm::operator=(const AForm& form)
{
  std::cout << "AForm " << mName << " copy assignation operator called\n";
  if (this == &form)
    return (*this);
  this->mSigned = form.mSigned;
  return (*this);
}

AForm::~AForm()
{
  std::cout << "AForm " << mName << " destructor called\n";
}

std::string AForm::getName() const
{
  return (mName);
}

bool AForm::getSign() const
{
  return (mSigned);
}

int AForm::getSignLevel() const
{
  return (mSignLevel);
}

int AForm::getExecLevel() const
{
  return (mExecLevel);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() <= mSignLevel
      && bureaucrat.getGrade() > 0 && mSignLevel <= 150)
    mSigned = true;
  else
    throw (GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw()
{
  return ("Grade too high\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
  return ("Grade too low\n");
}

const char* AForm::FormNotSignedException::what() const throw()
{
  return ("The form has not been signed\n");
}

void  AForm::execute(const Bureaucrat& executor) const
{
  if (mSigned == false)
    throw(FormNotSignedException());
  else if (executor.getGrade() > mExecLevel)
    throw(GradeTooLowException());
  else
    this->subExecute();
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
  out << form.getName()
  << (form.getSign() == true ? " has been signed," : " has not been signed,")
  << " it needs a grade of " << form.getSignLevel() << " to be signed"
  << " and a grade of " << form.getExecLevel() << " to be executed\n";
  return (out);
}
