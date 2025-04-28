#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target,
                                            int signLevel, int execLevel)
  :Form(target, signLevel, execLevel)
  ,mTarget(target)
{
  std::cout << "RRF " << mTarget << " constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& rrf)
  :Form(rrf.mTarget, rrf.getSignLevel(), rrf.getExecLevel())
  ,mTarget(rrf.mTarget)
{
  std::cout << "RRF " << mTarget << " copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=
(const RobotomyRequestForm& rrf)
{
  std::cout << "RRF " << mTarget << " assignement operator called\n";
  if (this == &rrf)
    return (*this);
  mTarget = rrf.mTarget;
  Form::operator=(rrf);
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << "RRF " << mTarget << " destructor called\n";
}

void RobotomyRequestForm::SubExecute()
{
  std::cout << "Dvuuuut Brrrrrrrrrrr\n";
  if (rand() % 2)
    std::cout << mTarget << " has been robotomized\n";
  else
    std::cout << mTarget << " the robotomy failed\n";
}
