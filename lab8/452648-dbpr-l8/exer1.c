#include <fcntl.h>

int main() {
    open("test.txt", O_WRONLY | O_CREAT, 0600);

    return 0;
}