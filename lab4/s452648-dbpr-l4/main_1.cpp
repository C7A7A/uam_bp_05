#include <pthread.h>

long var = 0;
const int size = 4;

void* increment(void* arg) {
    while (var < 10000000) {
        var++;
    }
    return NULL;
}

int main(void) {
     pthread_t threads[size]; 

    for (int i = 0; i < size; i++) {
       pthread_create(&threads[i], NULL, increment, NULL);
    }

    for (int i = 0; i < size; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}