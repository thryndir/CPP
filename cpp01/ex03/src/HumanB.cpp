#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
  :mName(name)
  ,mWeapon(0)
{}

void  HumanB::setWeapon(Weapon& Weapon)
{
  mWeapon = &Weapon;
}

void  HumanB::attack(void)
{
  std::cout << mName << " attacks with their " << mWeapon->getType() << '\n';
}
