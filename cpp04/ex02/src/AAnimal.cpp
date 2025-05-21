#include "AAnimal.hpp"
#include <iostream>

Animal::Animal(std::string type)
  :_type(type)
{
  std::cout << "animal constructor called\n";
}

Animal::Animal(const Animal& animal)
  :_type(animal._type)
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
  _type = animal._type;
  return (*this);
}

std::string Animal::getType() const
{
  return (_type);
}

void  Animal::makeSound() const
{
  std::cout << "????\n";
}
