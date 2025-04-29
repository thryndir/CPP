#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target,
                                            int signLevel, int execLevel)
  :AForm(target, signLevel, execLevel)
  ,mTarget(target)
{
  std::cout << "SCF " << mTarget << " constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& scf)
  :AForm(scf.mTarget, scf.getSignLevel(), scf.getExecLevel())
  ,mTarget(scf.mTarget)
{
  std::cout << "SCF " << mTarget << " copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=
(const ShrubberyCreationForm& scf)
{
  std::cout << "SCF " << mTarget << " assignement operator called\n";
  if (this == &scf)
    return (*this);
  mTarget = scf.mTarget;
  AForm::operator=(scf);
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "SCF " << mTarget << " destructor called\n";
}

void ShrubberyCreationForm::subExecute() const
{
  std::string out = mTarget + "_shrubbery";
  std::ofstream outfile(out.c_str());
  if (!outfile.is_open())
  {
    std::cerr << "Error: cannot open file " << out << " \n";
    return ;
  }
  outfile <<
"                  %%%,%%%%%%%\n"
"                   ,'%% //-*%%%%%%%\n"
"             ;%%%%%*%   _%%%%\n"
"              ,%%%       /(_.*%%%%.\n"
"              % *%%, ,%%%%*(    '\n"
"            %^     ,*%%% )/|,%%*%,_\n"
"                 *%    // #).-*%%*\n"
"                     _.) ,/ *%,\n"
"             _________/)#(_____________\n";
}
