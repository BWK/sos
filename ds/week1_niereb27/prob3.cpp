#include "IntCell.cpp"

int main () {
  const int arr_length = 5;

  IntCell *arr1 = new IntCell[arr_length];
  IntCell *arr2 = new IntCell[arr_length];

  for (int i=0; i<arr_length; i++) {
    arr1[i] = IntCell(i);
  }

  for (int i=0; i<arr_length; i++) {
    arr2[i] = arr[i];
  }

}
