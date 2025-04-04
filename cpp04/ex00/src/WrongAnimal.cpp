#include "WrongAnimal.hpp"
#include "iostream"

WrongAnimal::WrongAnimal(std::string type)
  :mType(type)
{
  std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal)
  :mType(WrongAnimal.mType)
{
  std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal)
{
  if (this == &WrongAnimal)
    return (*this);
  mType = WrongAnimal.mType;
  return (*this);
}

std::string WrongAnimal::getType() const
{
  return (mType);
}

void  WrongAnimal::makeSound() const
{
  std::cout << "is it wrong ????\n";
}
