#include <stdexcept>

template <typename T>
size_t easyfind(T container, int toFind)
{
  typename T::iterator it;
  typename T::iterator endIt = container.end();

  for (it = container.begin(); it != endIt; it++)
  {
    if (*it == toFind)
      return (*it);
  }
  throw (std::runtime_error("no occurence found\n"));
}
