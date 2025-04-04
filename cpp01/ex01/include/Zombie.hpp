#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
  std::string mName;
  public:
    Zombie(std::string name = "");
    void  setName(std::string name);
    void  announce(void) const;
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif
