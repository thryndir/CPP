#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
  Zombie* FirstZombie = new Zombie [N];
  for (int i = 0; i < N; i++)
  {
    FirstZombie[i].setName(name);
  }
  return (FirstZombie);
}
