#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat: public WrongAnimal
{
  public:
    explicit WrongCat(std::string type = "WrongCat");
    WrongCat(const WrongCat& wrongCat);
    virtual ~WrongCat();
    WrongCat& operator=(const WrongCat& wrongCat);
    void makeSound() const;
};

#endif
