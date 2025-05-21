#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
  std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& brain)
{
  for (int i = 0; i < 100; i++)
    _ideas[i] = brain._ideas[i];
  std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain& brain)
{
  std::cout << "Brain copy assignation operator called\n";
  if (this == &brain)
    return (*this);
  for (int i = 0; i < 100; i++)
    _ideas[i] = brain._ideas[i];
  return (*this);
}

Brain::~Brain()
{
  std::cout << "Brain destructor called\n";
}

void Brain::display(const std::string& name)
{
  for (int i = 0; i < 100; i++)
    std::cout << name << " " << _ideas[i] << "\n";
}

void Brain::setIdeas(const std::string& std)
{
  for (int i = 0; i < 100; i++)
    _ideas[i] = std;
}

