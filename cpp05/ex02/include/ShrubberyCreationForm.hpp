#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
  private:
    std::string mTarget;
  public:
    explicit ShrubberyCreationForm(const std::string& target, int signLevel = 25, int execLevel = 5);
    ShrubberyCreationForm(ShrubberyCreationForm& shrubberyCreationForm);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);
    virtual ~ShrubberyCreationForm();
    virtual void execute(const Bureaucrat& executor);
};

#endif
