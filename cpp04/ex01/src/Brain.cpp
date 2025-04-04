#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
  std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& brain)
{
  for (int i = 0; i < 100; i++)
    ideas[i] = brain.ideas[i];
  std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain& brain)
{
  if (this == &brain)
    return (*this);
  for (int i = 0; i < 100; i++)
    ideas[i] = brain.ideas[i];
  return (*this);
}

Brain::~Brain()
{
  std::cout << "Brain destructor called\n";
}
