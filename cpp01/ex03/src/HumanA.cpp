#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weaponType)
  :mName(name)
  ,mWeapon(weaponType)
{}

void  HumanA::attack(void)
{
  std::cout << mName << " attacks with their " << mWeapon.getType() << '\n';
}
