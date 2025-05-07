#ifndef DATA_HPP
#define DATA_HPP

#include "string"

class Data
{
  public:
    std::string mType;
    Data(const std::string& type);
    Data(const Data& data);
    Data& operator=(const Data& data);
    ~Data();
};

#endif
