// Rebar Niemi 
// first exercises

#include <iostream>

using namespace std;

int main () {
  const int size = 3;
  int arr[3];
  float avg = 0;
  int min, max = 0;

  for (int i=0; i < size; i++) {
    cout << "Enter an int: ";
    cin >> arr[i];
  }

  min = arr[0];
  for (int i=0; i<size; i++) {  
    avg += arr[i];
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
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
  cout << "Avg: " << avg << endl;
}


