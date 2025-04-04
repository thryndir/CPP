#include "Zombie.hpp"

void  randomChump(std::string name)
{
  Zombie NewBorn(name);
  NewBorn.announce();
}
