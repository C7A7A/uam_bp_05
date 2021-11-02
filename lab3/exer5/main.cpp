#include <cstdlib>
#include <stdio.h>
#include <iostream>

int main() {
  int *array = new int[5] {1, 2, 3, 4, 5};
  int *array2[2];

  for (int i = 0; i < 2; i++) {
    array2[i] = &array[i];
  }

  delete [] array;
  for (int i = 0; i < sizeof(array2)/sizeof(array2[0]); i++) {
    std::cout << *array2[i] << " ";
  }

  return 0;
}