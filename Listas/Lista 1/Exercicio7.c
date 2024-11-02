// 7. Escreva uma função que realize a intersecção entre dois vetores, retornado o resultado em um
// vetor alocado na heap. Considere que não há elementos repetidos dentro de um mesmo vetor.
// int* array_intersection(int n1, const int* v1, int n2, const int* v2)

#include <stdio.h>
#include <stdlib.h>

int* array_intersection(int n1, const int* v1, int n2, const int* v2){
    int* v3 = (int*) malloc(sizeof(int) * (n1 + n2));

    int k = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v1[i] == v2[j])
            {
                v3[k++] = v1[i];
            }
            
        }
        
    }

    return v3;
    
}

int main(){
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[5] = {3, 4, 5, 6, 7};

    int* v3 = array_intersection(5, v1, 5, v2);
    int k = 3;

    for (int i = 0; i < k; i++)
    {
        printf("%d ", v3[i]);
    }
    
    free(v3);

    return 0;
}

// 3 4 5
