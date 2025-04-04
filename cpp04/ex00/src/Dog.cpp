#include "Dog.hpp"
#include <iostream>

Dog::Dog(std::string type)
  :Animal(type)
{
  std::cout << "dog constructor called\n";
}

Dog::Dog(const Dog& dog)
  :Animal(dog.mType)
{
  std::cout << "dog copy constructor called\n";
}

Dog::~Dog()
{
  std::cout << "dog destructor called\n";
}

Dog& Dog::operator=(const Dog& dog)
{
  if (this == &dog)
    return (*this);
  mType = dog.mType;
  return (*this);
}

void  Dog::makeSound() const
{
  std::cout << "wouf\n";
}
