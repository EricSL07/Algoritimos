// 1. Escreva uma função que aloca na heap um array de inteiros de tamanho n, preenchido com zeros,
// e retorna seu endereço.
// int* create_vector(int n)
// Exemplo de uso da função:
// int* v1 = create_vector(7); // aloca array de 7 inteiros na heap
// print_vector(7, v1); // imprime 0,0,0,0,0,0,0
// free(v); // libera array alocado na heap

#include <stdio.h>
#include <stdlib.h>

int* create_vector(int n) {
    int* v = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
    return v;
}

void print_vector(int n, int* v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int* v1 = create_vector(7);
    print_vector(7, v1);
    free(v1);
    return 0;
}

