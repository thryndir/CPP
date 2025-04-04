#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
  protected:
    std::string mType;
  public:
    explicit WrongAnimal(std::string type = "");
    WrongAnimal(const WrongAnimal& wrongAnimal);
    virtual ~WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
    void makeSound() const;
    std::string getType() const;
  };

#endif
