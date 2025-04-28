#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
  private:
    std::string mTarget;
  public:
    explicit RobotomyRequestForm(const std::string& target, int signLevel = 25, int execLevel = 5);
    RobotomyRequestForm(RobotomyRequestForm& robotomyRequestForm);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequestForm);
    virtual ~RobotomyRequestForm();
    virtual void execute(const Bureaucrat& executor);
};

#endif
