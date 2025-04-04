#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
  ScavTrap test0("thryndir");
  ScavTrap test1("Roboto");
  test0.guardGate();
  test0.attack(test1.getName());
  test1.takeDamage(10);
  ScavTrap test2(test1);
  test2.attack(test0.getName());
  test0.takeDamage(30);
  test2 = test0;
  ClapTrap test3(test0);
  test3.attack(test0.getName());
  return 0;
}
