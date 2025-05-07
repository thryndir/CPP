#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
  public:
    Serializer(void);
    Serializer(const Serializer& serializer);
    Serializer& operator=(const Serializer& serializer);
    virtual ~Serializer() = 0;
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
