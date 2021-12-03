#include <stdio.h>
#include <stdlib.h>

char *getString(FILE* fp, size_t size) {
    char *str;
    int ch;
    size_t len = 0;

    // alloc given size to str
    str = realloc(NULL, sizeof(*str) * size);

    if (!str) return str;

    // read file until endline
    while (EOF != (ch = fgetc(fp)) && ch != '\n') {
        str[len++] = ch;
        // realloc if needed
        if (len == size) {
            str = realloc(str, sizeof(*str) * (size += 16));
            if (!str) return str;
        }
    }

    str[len++] = '\0';

    return realloc(str, sizeof(*str) * len);
}

int main() {
    char *data;

    data = getString(stdin, 8);
    size_t nbytes = snprintf(NULL, 0, "Podano: %s", data) + 1;

    char *str = malloc(nbytes);

    sprintf(str, "Podano: %s", data);

    printf("%s\n", str);

    free(str);
    free(data);
    return 0;
}