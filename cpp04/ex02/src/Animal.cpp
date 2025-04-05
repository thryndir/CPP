#include "Animal.hpp"
#include <iostream>

Animal::Animal(std::string type)
  :mType(type)
{
  std::cout << "animal constructor called\n";
}

Animal::Animal(const Animal& animal)
  :mType(animal.mType)
{
  std::cout << "animal copy constructor called\n";
}

Animal::~Animal()
{
  std::cout << "animal destructor called\n";
}

Animal& Animal::operator=(const Animal& animal)
{
  if (this == &animal)
    return (*this);
  mType = animal.mType;
  return (*this);
}

std::string Animal::getType() const
{
  return (mType);
}

void  Animal::makeSound() const
{
  std::cout << "????\n";
}
