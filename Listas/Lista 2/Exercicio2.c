// 2. Escreva uma função que receba um caminho de arquivo. Se o mesmo existir, faz nada. Se o
// arquivo não existir, tenta criá-lo. A função deve retornar 1 (um) caso arquivo exista ou tenha sido
// criado e, 0 (zero), caso contrário.
// int check_or_create(const char *filepath)

#include <stdio.h>
#include <stdlib.h>

int file_exists(const char* filepath) {
    FILE *file = fopen(filepath, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

int check_or_create(const char *filepath) {
    if (file_exists(filepath)) {
        return 1;
    }
    FILE *file = fopen(filepath, "w");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    int res = check_or_create("helloworld.txt");
    printf("%d\n", res);
    return 0;
}

