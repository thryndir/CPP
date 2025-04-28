#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
  private:
    const std::string mName;
    bool              mSigned;
    const int         mSignLevel;
    const int         mExecLevel;
  public:
    Form(const std::string& name, int signLevel = -1, int execLevel = -1, bool approved = false);
    Form(const Form& form);
    Form& operator=(const Form& form);
    virtual ~Form();
    std::string   getName() const;
    bool          getSign() const;
    int           getSignLevel() const;
    int           getExecLevel() const;
    void          beSigned(const Bureaucrat& bureaucrat);
    void          execute(const Bureaucrat& executor);
    virtual void  SubExecute(void) = 0;
    class GradeTooHighException: public std::exception
    {
      virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
      virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
