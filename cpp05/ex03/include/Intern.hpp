#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>
#include "AForm.hpp"

class Intern
{
  public:
    Intern();
    Intern(Intern& intern);
    Intern& operator=(const Intern& intern);
    ~Intern();
    AForm* makeForm(const std::string& name, const std::string& target);
    class FormNotFoundExcept : public std::exception
    {
      virtual const char* what() const throw();
    };
};

#endif
