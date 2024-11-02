// 9. Escreva uma função que aloca na heap uma matriz de inteiros de dimensões mxn e retorna o seu
// endereço. A matriz deve ser preenchida com uma sequência crescente de inteiros.
// int** create_vector2D(int m, int n)

#include <stdio.h>
#include <stdlib.h>

int** create_vector2D(int m, int n){
    int** v = (int**) malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++)
    {
        v[i] = (int*) malloc(sizeof(int) * n);
    }

    int k = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] = k++;
        }
        
    }

    return v;
    
}

int main(){
    int** v = create_vector2D(3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", v[i][j]);
        }

        printf("\n");
        
    }

    for (int i = 0; i < 3; i++)
    {
        free(v[i]);
    }

    free(v);

    return 0;
}

