#include <stdio.h>
#include <random>
#include <iostream>

void fill_matrix(int (&matrix)[100][100]);
void print_matrix(int matrix[100][100]);
void multiply_matrixes(int matrix1[100][100], int matrix2[100][100]);

int main() {
  int matrix1[100][100];
  int matrix2[100][100];

  srand(time(NULL));
  
  fill_matrix(matrix1);  
  fill_matrix(matrix2);

  // print_matrix(matrix1);
  // print_matrix(matrix2);

  multiply_matrixes(matrix1, matrix2);
 
  return 0;
}

void fill_matrix(int (&matrix)[100][100]) {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      matrix[i][j] = rand() % 2;
    }
  }
}
void print_matrix(int matrix[100][100]) {
  std::cout << "MATRIX" << std::endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
}

void multiply_matrixes(int matrix1[100][100], int matrix2[100][100]){
  int matrix100[100][100] = { 0 };

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      for (int k = 0; k < 100; k++) {
        matrix100[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // print_matrix(matrix100);
}
