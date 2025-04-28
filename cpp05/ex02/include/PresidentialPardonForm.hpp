#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
  private:
    std::string mTarget;
  public:
    explicit PresidentialPardonForm(const std::string& target, int signLevel = 25, int execLevel = 5);
    PresidentialPardonForm(PresidentialPardonForm& presidentialPardonForm);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialPardonForm);
    virtual ~PresidentialPardonForm();
    virtual void execute(const Bureaucrat& executor);
};

#endif
