// 2. Escreva uma função que receba um vetor de inteiros e seu tamanho n. A função deve retornar o
// endereço de um novo vetor, alocado na heap, contendo os max maiores elementos contidos no
// vetor original. OBS: você pode modificar o conteúdo do vetor original, se necessário.
// int* get_largest(int n, int* v, int max)
// Exemplo de uso da função:
// int v0[] = {6,10,2,1,2,3,9}
// int* v1 = get_largest(7, v0, 2); // retorna vetor com os 2 maiores valores de v0
// print_vector(2, v1); // imprime 10,9
// free(v1); // libera array alocado na heap

#include <stdio.h> 
#include <stdlib.h>

int* get_largest(int n, int* v, int max){
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < n; i++)
        {
           if (v[i - 1] > v[i]){
               max = v[i - 1];
            }
      }
    }
    
    

}

int print_vector(int n, int* v){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    

    return 0;
}

int main(){
    int v0[] = {6,10,2,1,2,3,9};
    int* v1 = get_largest(7, v0, 2);
    print_vector(2, v1);
    free(v1);

    return 0;
}