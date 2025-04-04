#include "Zombie.hpp"

int main(void)
{
  Zombie* Test = newZombie("gneugneu");
  Test->announce();
  randomChump("gaga");
  delete Test;
  return (0);
}
