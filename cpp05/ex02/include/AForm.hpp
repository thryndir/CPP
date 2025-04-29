#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
  private:
    const std::string mName;
    bool              mSigned;
    const int         mSignLevel;
    const int         mExecLevel;
  public:
    AForm(const std::string& name = "", int signLevel = -1, int execLevel = -1, bool approved = false);
    AForm(const AForm& form);
    AForm& operator=(const AForm& form);
    virtual ~AForm();
    std::string   getName() const;
    bool          getSign() const;
    int           getSignLevel() const;
    int           getExecLevel() const;
    void          beSigned(const Bureaucrat& bureaucrat);
    void          execute(const Bureaucrat& executor) const;
    virtual void  subExecute(void) const = 0;
    class GradeTooHighException: public std::exception
    {
      virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
      virtual const char* what() const throw();
    };
    class FormNotSignedException: public std::exception
    {
      virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
