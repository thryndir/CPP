#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

Serializer::Serializer(void)
{}

Serializer::Serializer(const Serializer& serializer)
{
  (void)serializer;
}

Serializer& Serializer::operator=(const Serializer& serializer)
{
  if (this == &serializer)
    return (*this);
  return (*this);
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize(Data* ptr)
{
  uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
  return (result);
}

Data* Serializer::deserialize(uintptr_t raw)
{
  Data* result = reinterpret_cast<Data*>(raw);
  return (result);
}
