#include "Zombie.hpp"
#include <iostream>

void  Zombie::announce(void) const
{
  std::cout << mName << ": BraiiiiiiinnnzzzZ...\n";
}

void  Zombie::setName(std::string name)
{
  mName = name;
}

Zombie::Zombie(std::string Name)
  :mName(Name)
{}

Zombie::~Zombie()
{
  std::cout << mName << std::endl;
}
