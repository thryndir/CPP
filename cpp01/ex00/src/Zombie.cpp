#include "Zombie.hpp"
#include <iostream>

void  Zombie::announce(void) const
{
  std::cout << mName << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
  std::cout << mName << std::endl;
}
