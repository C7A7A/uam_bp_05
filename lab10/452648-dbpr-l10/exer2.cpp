#include <bits/stdc++.h>
#include <stdexcept>

class SafeArray {
  private:
    int size;
    int* array;

  public:
    SafeArray(int size) {
      setSize(size);
    }

    void setSize(int size) {
      this->size = size;
      array = new int[size];
      fillArrayWithZeroes();
    }

    int getSize() {
      return size;
    }

    void fillArrayWithZeroes() {
      for(int i = 0; i < size; i++) {
        array[i] = 0;
      }
    }

    void printArray() {
      for(int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
      }
      std::cout << std::endl;
    }

    void printAtIndex(int index) {
      if (index >= 0 && index < size) {
        std::cout << array[index] << std::endl;
      } else {
        std::cout << "Index is out of boundry" << std::endl;
      }
    }

    void setAtIndex(int index, int value) {
      if (index >= 0 && index < size) {
        array[index] = value;
      } else {
        std::cout << "Index is out of boundry" << std::endl;
      }
    }

};


int main() {
  SafeArray myArr(10);
  std::cout << myArr.getSize() << std::endl;
  myArr.setAtIndex(0, 150);
  myArr.printAtIndex(0);
  myArr.setAtIndex(3, -3);
  myArr.printAtIndex(3);
  myArr.setAtIndex(9, 9);
  myArr.printAtIndex(9);
  myArr.printArray();

  myArr.setAtIndex(10, 122);
  myArr.printAtIndex(10);
  myArr.setAtIndex(-1, 122);


  myArr.setSize(15);
  std::cout << myArr.getSize() << std::endl;
  myArr.printArray();
  for (int i = 0; i < 15; i++) {
    myArr.setAtIndex(i, i);
  }
  myArr.printArray();

  return 0;
}