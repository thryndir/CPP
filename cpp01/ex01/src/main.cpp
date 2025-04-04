#include "Zombie.hpp"

int main(void)
{
  Zombie* Test = zombieHorde(10, "Jack");
  for (int i = 0; i <= 9; i++)
    Test->announce();
  delete[] Test;
  return (0);
}
