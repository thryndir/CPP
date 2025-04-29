#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat
{
  private:
    const std::string mName;
    int  mGrade;
  public:
    Bureaucrat(const std::string& name = "", int grade = -1);
    Bureaucrat(const Bureaucrat& bureaucrat);
    Bureaucrat& operator=(const Bureaucrat& bureaucrat);
    ~Bureaucrat();
    std::string getName(void) const;
    int  getGrade(void) const;
    void  increaseGrade();
    void  decreaseGrade();
    class GradeTooHighException: public std::exception
    {
      virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
      virtual const char* what() const throw();
    };
};

  std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
