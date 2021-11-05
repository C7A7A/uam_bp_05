#include <sys/mman.h>
#include <iostream>
#include <stdlib.h>
#include <charconv>

const int size = 16;

int main() {
    char preKey[16];
    // srand(time(NULL));

    if (mlock(&preKey, size) == 0) {
        std::cout << "LOCKED";
        for (int i = 0; i < size; i++) {
            int ch = std::to_chars((rand() % 2));
            std::cout << "ch: " << ch << std::endl;
            preKey[i] = ch;
            std::cout << preKey[i];
        }
    } else {
        std::cout << "NOT LOCKED";
    }

    

    munlock(&preKey, size);

    return 0;
}