//IntCell implementation

#include "IntCell.h"

IntCell::IntCell (int initialValue) : storedValue(initialValue) 
{
}

int IntCell::read () const
{
  return storedValue;
}

void IntCell::write (int x)
{
  storedValue = x;
}

IntCell IntCell::operator+ (const IntCell &x) 
{
  return IntCell(this->read() + x.read());
}

void IntCell::operator+ (int x)
{
  this->write(this->read() + x);
}

IntCell IntCell::operator- (const IntCell &x)
{
  return IntCell(this->read() - x.read());
}

void IntCell::operator- (int x)
{
  this->write(this->read() - x);
}

std::ostream& operator<< (std::ostream& stream, const IntCell &x)
{
  stream << x.storedValue;
}

