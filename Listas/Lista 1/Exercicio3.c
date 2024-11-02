#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copy_string(const char* str) {
    int tamanho = strlen(str);

    char* copia = (char*) malloc(sizeof(char) * (tamanho + 1)); // +1 para o caractere nulo

    for (int i = 0; i < tamanho; i++) {
        copia[i] = str[i];
    }

    copia[tamanho] = '\0'; // Adiciona o caractere nulo no final

    return copia;
}

int main() {
    char* string = "Hello World!";
    char* copia = copy_string(string);
    printf("%s\n", copia);
    free(copia);
    return 0;
}