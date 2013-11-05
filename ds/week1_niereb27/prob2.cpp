
#include <iostream>
#include "IntCell.cpp"
using namespace std;

int main () {
 const int size = 3;
  IntCell arr[3];
  float avg = 0;
  int min, max = 0;

  for (int i=0; i < size; i++) {
    cout << "Enter an int: ";
    int tmp;
    cin >> tmp;
    arr[i].write(tmp);
  }

  min = arr[0].read();
  for (int i=0; i<size; i++) {
    avg += arr[i].read();
    if (arr[i].read() > max) max = arr[i].read();
    if (arr[i].read() < min) min = arr[i].read();
  }
  avg /= size;

  cout << "Forwards: " << endl;
  for (int i=0; i<size; i++)
    cout << arr[i] << endl;
  cout << "Backwards: " << endl;
  for (int i=size-1; i>=0; i--)
    cout << arr[i] << endl;
  cout << "Max: " << max << endl;
  cout << "Min: " << min << endl;
  cout << "Avg: " << avg <<  endl;
}
