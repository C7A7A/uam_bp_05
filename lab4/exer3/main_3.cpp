#include <pthread.h>

long var = 0;

void increment() {
    while (var < 10000000) {
        var++;
    }
}

int main(void) {
    increment();

    return 0;
}