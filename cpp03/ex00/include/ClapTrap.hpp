#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
  protected:
    std::string  mName;
    int          mHitPoints;
    int          mEnergyPoints;
    int          mAttackDamage;
  public:
    ClapTrap(const std::string& name = "", int hPoints = 10
      ,int ePoints = 10, int aDamgage = 0);
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap&  operator=(const ClapTrap& clapTrap);
    ~ClapTrap();
    void                attack(const std::string& target);
    void                takeDamage(unsigned int amount);
    void                beRepaired(unsigned int amount);
    const std::string&  getName(void) const;
    int                 getHpoints(void) const;
    int                 getEpoints(void) const;
    int                 getAdamage(void) const;
    void                setName(const std::string& name);
    void                setHpoints(const int hPoints);
    void                setEpoints(const int hePoints);
    void                setAdamage(const int aDamage);
};

#endif
