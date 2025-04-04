#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int  Fixed::mFrac = 8;

Fixed::Fixed()
  :mFix(0)
{
  std::cout << "Default constructor called \n";
}

Fixed::Fixed(const int fixed)
  :mFix(fixed * int(1 << mFrac))
{
  std::cout << "Int constructor called \n";
}

Fixed::Fixed(const float fixed)
  :mFix(float(round(float(fixed) * float((1 << mFrac)))))
{
  std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
  :mFix(fixed.mFix)
{
  std::cout << "Copy constructor called \n";
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
  std::cout << "Copy assignement operateur called\n";
  if (this == &fixed)
    return (*this);
  this->setRawBits(fixed.mFix);
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

int  Fixed::toInt(void) const
{
  return ((int)mFix / int((1 << mFrac)));
}

float  Fixed::toFloat(void) const
{
  return ((float)mFix / float((1 << mFrac)));
}

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed)
{
  out << fixed.toFloat();
  return (out);
}
