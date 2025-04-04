#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
  private:
    std::string mName;
    Weapon& mWeapon;
  public:
    HumanA(const std::string& name, Weapon& weaponType);
    void  attack(void);
};

#endif
