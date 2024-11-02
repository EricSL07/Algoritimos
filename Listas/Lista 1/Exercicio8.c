// 8. Escreva uma função que recebe o endereço e as dimensões de uma matriz alocada na heap. A
// função deve imprimir seu conteúdo. Lembre-se: dentro da função, o acesso aos elementos da
// matriz v ocorre normalmente por meio do operador de índice. Ex: v[0][2].
// void print_vector2D(int m, int n, const int** v)

#include <stdio.h>
#include <stdlib.h>

void print_vector2D(int m, int n, const int** v){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", v[i][j]);
        }
        
    }
    
}

int main(){
    int** v = (int**) malloc(sizeof(int*) * 3);

    for (int i = 0; i < 3; i++)
    {
        v[i] = (int*) malloc(sizeof(int) * 3);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            v[i][j] = i + j;
        }
        
    }

    print_vector2D(3, 3, (const int**) v);

    for (int i = 0; i < 3; i++)
    {
        free(v[i]);
    }

    free(v);

    return 0;
}

// 0 1 2 1 2 3 2 3 4

