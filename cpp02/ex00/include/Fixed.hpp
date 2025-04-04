#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
  private:
    int         mFix;
    const static int  mFrac;
  public:
    Fixed(int fix = 0);
    Fixed(const Fixed& fixed);
    Fixed&  operator=(const Fixed& fixed);
    ~Fixed();
    int  getRawBits(void) const;
    void  setRawBits(const int raw);
};

#endif
