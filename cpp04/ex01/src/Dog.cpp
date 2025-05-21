#include "Dog.hpp"
#include <iostream>

Dog::Dog(std::string type)
  :Animal(type)
{
  std::cout << "dog constructor called\n";
  _brain = new Brain;
}

Dog::Dog(const Dog& dog)
  :Animal(dog._type)
{
  std::cout << "dog copy constructor called\n";
  _brain = new Brain(*(dog._brain));
}

Dog::~Dog()
{
  std::cout << "dog destructor called\n";
  delete _brain;
}

Dog& Dog::operator=(const Dog& dog)
{
  std::cout << "dog assignation operator called\n";
  if (this == &dog)
    return (*this);
  if (_brain)
    delete _brain;
  _brain = new Brain(*(dog._brain));
  _type = dog._type;
  return (*this);
}

void  Dog::makeSound() const
{
  std::cout << "wouf\n";
}

Brain& Dog::getBrain(void)
{
  return (*_brain);
}
