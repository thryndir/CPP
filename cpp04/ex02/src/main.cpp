#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  const WrongAnimal* test = new WrongAnimal();
  const WrongAnimal* test1 = new WrongCat();
  std::cout << test->getType() << " " << std::endl;
  std::cout << test1->getType() << " " << std::endl;
  test->makeSound();
  test1->makeSound();
  delete j;
  delete i;
  delete test;
  delete test1;
  std::cout << std::endl;
  const int n = 100;
  Animal* animal[n];
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
      animal[i] = new Cat();
    else
      animal[i] = new Dog();
    std::cout << std::endl;
  }
  animal[0]->makeSound();
  animal[1]->makeSound();
  for (int i = 0; i < n; i++)
  {
     delete animal[i];
     std::cout << std::endl;
  }
  return 0;
}
