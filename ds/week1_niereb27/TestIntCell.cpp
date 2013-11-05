// Testing IntCell

#include <iostream>
#include "IntCell.h"
#include "IntCell.cpp"

using namespace std;

int main()
{
  IntCell m;
  IntCell n;

  m.write(5);
  n.write(2);

  IntCell o = m + n;
  IntCell p = m - n;
  cout << "Cell contents m: " << m << endl;
  cout << "Cell contents n: " << n.read() << endl;
  cout << "Cell contents o: " << o.read() << endl;
  cout << "Cell contents p: " << p.read() << endl;
  return 0;
}
