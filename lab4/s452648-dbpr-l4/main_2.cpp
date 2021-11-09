#include <pthread.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
long var = 0;
const int size = 4;

void* increment(void* arg) {
    for (int i = 0; i < 10000000/size; i++) {
        
        pthread_mutex_lock(&mut);
        var++;
        pthread_mutex_unlock(&mut);

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