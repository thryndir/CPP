#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie* NewZombie = new Zombie(name);
    return (NewZombie);
}
