#include "Dog.hpp"
#include <iostream>

Dog::Dog(std::string type)
  :Animal(type)
{
  std::cout << "dog constructor called\n";
  brain = new Brain;
}

Dog::Dog(const Dog& dog)
  :Animal(dog.mType)
  ,brain(dog.brain)
{
  std::cout << "dog copy constructor called\n";
}

Dog::~Dog()
{
  std::cout << "dog destructor called\n";
  delete brain;
}

Dog& Dog::operator=(const Dog& dog)
{
  std::cout << "dog assignation operator called\n";
  if (this == &dog)
    return (*this);
  mType = dog.mType;
  brain = dog.brain;
  return (*this);
}

void  Dog::makeSound() const
{
  std::cout << "wouf\n";
}
