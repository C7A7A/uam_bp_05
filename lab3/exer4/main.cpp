#include <stdio.h>

int main() {
  int *array = new int[10];
  for (int i = 0; i < 20; i++) {
    // przypisanie wartości do indesku spoza tablicy dla i > 9, poprawnie: for (int i = 0; i < 10; i++)
    array[i] = i;
  }
  // przypisanie wartości do indeksu spoza tablicy, poprawnie: np. array[5] = 15
  array[100] = 15;

  delete [] array;
  // 2 zwolnienie tego samego bloku pamięci, poprawnie: nie zwalnienie tego samego bloku pamięci więcej niż raz
  delete [] array;

  return 0;
}