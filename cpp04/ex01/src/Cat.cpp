#include "Cat.hpp"
#include <iostream>

Cat::Cat(std::string type)
  :Animal(type)
{
  std::cout << "cat constructor called\n";
  _brain = new Brain;
}

Cat::Cat(const Cat& cat)
  :Animal(cat._type)
{
  std::cout << "cat copy constructor called\n";
  _brain = new Brain(*(cat._brain));
}

Cat::~Cat()
{
  std::cout << "cat destructor called\n";
  delete _brain;
}

Cat& Cat::operator=(const Cat& cat)
{
  std::cout << "cat assignation operator called\n";
  if (this == &cat)
    return (*this);
  if (_brain)
    delete _brain;
  _brain = new Brain(*(cat._brain));
  _type = cat._type;
  return (*this);
}

void  Cat::makeSound() const
{
  std::cout << "meow\n";
}

Brain& Cat::getBrain(void)
{
  return (*_brain);
}
