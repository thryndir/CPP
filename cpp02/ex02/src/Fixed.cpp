#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int  Fixed::mFrac = 8;

Fixed::Fixed()
  :mFix(0)
{
}

Fixed::Fixed(const int fixed)
  :mFix(fixed * int(1 << mFrac))
{
}

Fixed::Fixed(const float fixed)
  :mFix(float(round(float(fixed) * float((1 << mFrac)))))
{
}

Fixed::Fixed(const Fixed& fixed)
  :mFix(fixed.mFix)
{
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
  if (this == &fixed)
    return (*this);
  this->setRawBits(fixed.mFix);
  return (*this);
}

Fixed::~Fixed()
{
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

Fixed&  Fixed::min(Fixed& fixed0, Fixed& fixed1)
{
  return (fixed0 < fixed1 ? fixed0 : fixed1);
}

const Fixed&  Fixed::min(const Fixed& fixed0, const Fixed& fixed1)
{
  return (fixed0 < fixed1 ? fixed0 : fixed1);
}

Fixed&  Fixed::max(Fixed& fixed0, Fixed& fixed1)
{
  return (fixed0 > fixed1 ? fixed0 : fixed1);
}

const Fixed&  Fixed::max(const Fixed& fixed0, const Fixed& fixed1)
{
  return (fixed0 > fixed1 ? fixed0 : fixed1);
}

bool  Fixed::operator>(const Fixed& fixed) const
{
  return (this->mFix > fixed.mFix ? true : false);
}

bool  Fixed::operator<(const Fixed& fixed) const
{
  return (this->mFix < fixed.mFix ? true : false);
}

bool  Fixed::operator>=(const Fixed& fixed) const
{
  return (this->mFix >= fixed.mFix ? true : false);
}

bool  Fixed::operator<=(const Fixed& fixed) const
{
  return (this->mFix <= fixed.mFix ? true : false);
}

bool  Fixed::operator==(const Fixed& fixed) const
{
  return (this->mFix == fixed.mFix ? true : false);
}

bool  Fixed::operator!=(const Fixed& fixed) const
{
  return (this->mFix != fixed.mFix ? true : false);
}

Fixed  Fixed::operator+(const Fixed& fixed)
{
  return (float(this->toFloat() + fixed.toFloat()));
}

Fixed  Fixed::operator-(const Fixed& fixed)
{
  return (float(this->toFloat() - fixed.toFloat()));
}

Fixed  Fixed::operator*(const Fixed& fixed)
{
  return (float(this->toFloat() * fixed.toFloat()));
}

Fixed  Fixed::operator/(const Fixed& fixed)
{
  return (float(this->toFloat() / fixed.toFloat()));
}

Fixed&  Fixed::operator++()
{
  this->mFix++;
  return (*this);
}

Fixed  Fixed::operator++(int)
{
  Fixed  temp = *this;
  this->mFix++;
  return (temp);
}

Fixed&  Fixed::operator--()
{
  this->mFix--;
  return (*this);
}

Fixed  Fixed::operator--(int)
{
  Fixed  temp = *this;
  this->mFix++;
  return (temp);
}

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed)
{
  out << fixed.toFloat();
  return (out);
}
