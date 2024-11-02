// 6. Escreva uma função que realize a união entre dois vetores, retornado o resultado em um vetor
// alocado na heap. Considere que não há elementos repetidos dentro de um mesmo vetor.
// int* array_union(int n1, const int* v1, int n2, const int* v2)

#include <stdio.h>
#include <stdlib.h>

int* array_union(int n1, const int* v1, int n2, const int* v2) {
    int* result = (int*) malloc((n1 + n2) * sizeof(int));
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    int i, j;
    for (i = 0; i < n1; i++) {
        result[i] = v1[i];
    }

    for (j = 0; j < n2; j++) {
        result[i + j] = v2[j];
    }

    return result;
}

void print_array(int n, int* v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v1[] = {1, 2, 3, 4, 4};
    int v2[] = {4, 5, 6, 7};

    int* result = array_union(5, v1, 4, v2);

    print_array(9, result);

    free(result);

    return 0;
}
