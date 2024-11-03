// 1. Escreva uma função que verifica se o arquivo de caminho informado existe (retorna 1). Caso
// contrário, retorna 0.
// int file_exists(const char* filepath)
// Exemplo de uso da função:
// int res = file_exists("C:\documentos\programa.exe"); // retorna 1 se existir

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

int main() {
    int res = file_exists("C:\\Users\\gabri\\Documents\\GitHub\\Listas\\Lista 2\\Exercicio1.c");
    printf("%d\n", res);
    return 0;
}