// 10. Escreva uma função que receba uma matriz na stack como entrada e retorne o endereço de sua
// transposta, alocada na heap.
// int** transpose(int m, int n, int v[m][n])

#include <stdio.h>
#include <stdlib.h>

int** transpose(int m, int n, int v[m][n]){
    int** v2 = (int**) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        v2[i] = (int*) malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v2[j][i] = v[i][j];
        }
        
    }
    
    return v2;
}

int main(){
    int v[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int** v2 = transpose(3, 4, v);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", v2[i][j]);
        }

        printf("\n");
        
    }

    for (int i = 0; i < 4; i++)
    {
        free(v2[i]);
    }

    free(v2);

    return 0;
}