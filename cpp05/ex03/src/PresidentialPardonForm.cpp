#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target,
                                            int signLevel, int execLevel)
  :AForm(target, signLevel, execLevel)
  ,mTarget(target)
{
  std::cout << "PPF " << mTarget << " constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& ppf)
  :AForm(ppf.mTarget, ppf.getSignLevel(), ppf.getExecLevel())
{
  std::cout << "PPF " << mTarget << " copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=
(const PresidentialPardonForm& ppf)
{
  std::cout << "PPF " << mTarget << " assignement operator called\n";
  if (this == &ppf)
    return (*this);
  mTarget = ppf.mTarget;
  AForm::operator=(ppf);
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "PPF " << mTarget << " destructor called\n";
}

void PresidentialPardonForm::subExecute() const
{
  std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox\n";
}
