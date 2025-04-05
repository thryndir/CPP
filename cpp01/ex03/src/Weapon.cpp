#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string weaponType)
  :mType(weaponType)
{}

void  Weapon::setType(const std::string& str)
{
  mType = str;
}

const std::string& Weapon::getType() const
{
  return (mType);
}
