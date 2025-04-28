#include "Form.hpp"
#include <iostream>

Form::Form(const std::string& name, int signLevel, int execLevel, bool approved)
  :mName(name)
  ,mSigned(approved)
  ,mSignLevel(signLevel)
  ,mExecLevel(execLevel)
{
  std::cout << "Form " << mName << " constructor called\n";
  if (mSignLevel > 150 || mExecLevel > 150)
    throw (GradeTooHighException());
  else if (mSignLevel < 1 || mExecLevel < 1)
    throw (GradeTooLowException());
}

Form::Form(const Form& form)
  :mName(form.mName)
  ,mSigned(form.mSigned)
  ,mSignLevel(form.mSignLevel)
  ,mExecLevel(form.mExecLevel)
{
  std::cout << "Form " << mName << " copy constructor called\n";
  if (mSignLevel > 150 || mExecLevel > 150)
    throw (GradeTooHighException());
  else if (mSignLevel < 1 || mExecLevel < 1)
    throw (GradeTooLowException());
}

Form& Form::operator=(const Form& form)
{
  std::cout << "Form " << mName << " copy assignation operator called\n";
  if (this == &form)
    return (*this);
  this->mSigned = form.mSigned;
  return (*this);
}

Form::~Form()
{
  std::cout << "Form " << mName << " destructor called\n";
}

std::string Form::getName() const
{
  return (mName);
}

bool Form::getSign() const
{
  return (mSigned);
}

int Form::getSignLevel() const
{
  return (mSignLevel);
}

int Form::getExecLevel() const
{
  return (mExecLevel);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() <= mSignLevel
      && bureaucrat.getGrade() > 0 && mSignLevel <= 150)
    mSigned = true;
  else
    throw (GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw()
{
  return ("Grade too high\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
  return ("Grade too low\n");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
  out << form.getName()
  << (form.getSign() == true ? " has been signed," : " has not been signed,")
  << " it needs a grade of " << form.getSignLevel() << " to be signed"
  << " and a grade of " << form.getExecLevel() << " to be executed\n";
  return (out);
}
