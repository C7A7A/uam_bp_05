#include <sys/mman.h>
#include <iostream>
#include <stdlib.h>
#include <charconv>

const int size = 16;

int main() {
    char preKey[size];
    srand(time(NULL));

    if (mlock(&preKey, size) == 0) {
        std::cout << "Memory locked\n" << "preKey: ";
        for (int i = 0; i < size; i++) {
            preKey[i] = '0' + (rand() % 2);
            std::cout << preKey[i];
        }
        if (munlock(&preKey, size) == 0) {
            std::cout << "\nMemory unlocked"; 
        }
    } 

    return 0;
}