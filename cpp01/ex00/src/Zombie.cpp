#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
  :mName(name)
{}

void  Zombie::announce(void) const
{
  std::cout << mName << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
  std::cout << mName << std::endl;
}
