#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap test("test");
  test.attack("test");
  test.beRepaired(8);
  test.takeDamage(10);
  return 0;
}
