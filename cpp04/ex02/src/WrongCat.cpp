#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(std::string type)
  :WrongAnimal(type)
{
  std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat& Wrongcat)
  :WrongAnimal(Wrongcat.mType)
{
  std::cout << "WrongCat copy constructor called\n";
}

WrongCat::~WrongCat()
{
  std::cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& cat)
{
  std::cout << "WrongCat assignation operator called\n";
  if (this == &cat)
    return (*this);
  mType = cat.mType;
  return (*this);
}

void  WrongCat::makeSound() const
{
  std::cout << "miouuuu\n";
}
