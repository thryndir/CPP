#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
  private:
    std::string mTarget;
  public:
    RobotomyRequestForm(const std::string& target = "", int signLevel = 72, int execLevel = 45);
    RobotomyRequestForm(RobotomyRequestForm& robotomyRequestForm);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequestForm);
    virtual ~RobotomyRequestForm();
    virtual void subExecute(void) const;
};

#endif
