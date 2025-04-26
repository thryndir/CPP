#include "Cat.hpp"
#include <iostream>

Cat::Cat(std::string type)
  :Animal(type)
{
  std::cout << "cat constructor called\n";
  brain = new Brain;
}

Cat::Cat(const Cat& cat)
  :Animal(cat.mType)
  ,brain(cat.brain)
{
  std::cout << "cat copy constructor called\n";
}

Cat::~Cat()
{
  std::cout << "cat destructor called\n";
  delete brain;
}

Cat& Cat::operator=(const Cat& cat)
{
  std::cout << "cat assignation operator called\n";
  if (this == &cat)
    return (*this);
  mType = cat.mType;
  brain = cat.brain;
  return (*this);
}

void  Cat::makeSound() const
{
  std::cout << "meow\n";
}
