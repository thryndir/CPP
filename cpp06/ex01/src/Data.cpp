#include "Data.hpp"
#include <iostream>

Data::Data(const std::string& type)
  :mType(type)
{
  std::cout << "Data " << mType << "constructor called\n";
}

Data::Data(const Data& data)
  :mType(data.mType)
{
  std::cout << "Data " << mType << "copy constructor called\n";
}

Data& Data::operator=(const Data& data)
{
  std::cout << "Data " << mType << "copy operator called\n";
  if (this == &data)
    return (*this);
  mType = data.mType;
  return (*this);
}

Data::~Data()
{
  std::cout << "Data " << mType << "destructor called\n";
}
