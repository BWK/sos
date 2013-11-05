//IntCell interfact

#ifndef IntCell_H
#define IntCell_H
#include <iostream>

class IntCell 
{
  public:
    explicit IntCell(int initialValue = 0);
    int read() const;
    void write(int x);
    IntCell operator+ (const IntCell &x);
    IntCell operator- (const IntCell &x); 
    void operator+ (int x);
    void operator- (int x);
    friend std::ostream& operator<< (std::ostream&, const IntCell&);
    
  private:
    int storedValue;
};

#endif
