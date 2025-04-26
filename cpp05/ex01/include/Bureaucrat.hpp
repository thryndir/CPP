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
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& bureaucrat);
    Bureaucrat& operator=(const Bureaucrat& bureaucrat);
    ~Bureaucrat();
    std::string getName(void);
    int  getGrade(void);
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

  std::ostream& operator<<(std::ostream& out, Bureaucrat bureaucrat);

#endif
