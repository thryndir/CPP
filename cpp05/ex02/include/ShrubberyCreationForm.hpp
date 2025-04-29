#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
  private:
    std::string mTarget;
  public:
    ShrubberyCreationForm(const std::string& target = "", int signLevel = 145, int execLevel = 137);
    ShrubberyCreationForm(ShrubberyCreationForm& shrubberyCreationForm);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);
    virtual ~ShrubberyCreationForm();
    virtual void subExecute(void) const;
};

#endif
