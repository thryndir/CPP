#include "Fixed.hpp"
#include <iostream>

const int  Fixed::mFrac = 8;

Fixed::Fixed(int fix)
  :mFix(fix)
{
  std::cout << "Default constructor called \n";
}

Fixed::Fixed(const Fixed& fixed)
  :mFix(fixed.mFix)
{
  std::cout << "Copy constructor called \n";
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
  if (this == &fixed)
    return (*this);
  std::cout << "Copy assignement operateur called\n";
  this->setRawBits(fixed.getRawBits());
  return (*this);
}

Fixed::~Fixed()
{
  std::cout << "Destructor called\n";
}

int  Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called\n";
  return (mFix);
}

void  Fixed::setRawBits(const int raw)
{
  mFix = raw;
}
