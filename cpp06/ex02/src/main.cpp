#include <iostream>
#include <stdlib.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void)
{
  int whichClass = rand() % 3;
  switch(whichClass)
  {
      case 0: return (new A());
      case 1: return (new B());
      case 2: return (new C());
      default: return (new A());
  }
}

void identify(Base* p)
{
  A* a = dynamic_cast<A*>(p);
  B* b = dynamic_cast<B*>(p);
  C* c = dynamic_cast<C*>(p);
  if (a != NULL)
    std::cout << "the type of p is A\n";
  else if (b != NULL)
    std::cout << "the type of p is B\n";
  else if (c != NULL)
    std::cout << "the type of p is C\n";
}

void identify(Base& p)
{
  try
  {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "the type of p is A\n";
  }
  catch (const std::exception& e)
  {}
  try
  {
    B& b = dynamic_cast<B&>(p);
    (void)b;
    std::cout << "the type of p is B\n";
  }
  catch (const std::exception& e)
  {}
  try
  {
    C& c = dynamic_cast<C&>(p);
    (void)c;
    std::cout << "the type of p is C\n";
  }
  catch (const std::exception& e)
  {}
}

int main(void)
{
  srand(time(NULL));
  Base* base = generate();
  Base* base2 = new A;
  Base& base3 = *(new C());
  identify(base);
  identify(base2);
  identify(base3);
  return (0);
}
