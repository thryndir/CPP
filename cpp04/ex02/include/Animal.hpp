#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  protected:
    std::string mType;
  public:
    Animal(std::string type = "");
    Animal(const Animal& animal);
    virtual ~Animal();
    Animal& operator=(const Animal& animal);
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif
