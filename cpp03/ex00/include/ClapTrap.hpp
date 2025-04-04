#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
  private:
    std::string  mName;
    int          mHitPoints;
    int          mEnergyPoints;
    int          mAttackDamage;
  public:
    explicit ClapTrap(const std::string& name = "");
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap&  operator=(const ClapTrap& clapTrap);
    ~ClapTrap();
    void  attack(const std::string& target);
    void  takeDamage(unsigned int amount);
    void  beRepaired(unsigned int amount);
};

#endif
