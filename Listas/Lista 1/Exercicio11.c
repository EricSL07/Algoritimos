// 11. Escreva uma função que receba o endereço de uma string contendo palavras separadas por
// espaços. A função deve retornar o endereço de um vetor de strings (matriz de caracteres) contendo
// as palavras separadas. Além disso, deve retornar, via parâmetro, o número de palavras
// encontradas.
// char** split(const char* str, int* n)
// Exemplo de uso da função:
// char str[] = " Texto de teste com várias palavras ";
// int size = 0;
// char** tokens = split(str, &size); // devolve vetor de strings com as palavras
// for (int i = 0; i < size; i++)
// printf("%s\n", tokens[i]); // imprime as palavras encontradas
// // libera vetor de strings alocado na heap
// for (int i = 0; i < size; i++)
// free(tokens[i]);
// free(tokens);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char* str, int* n){
    int size = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            size++;
        }
        
        i++;
    }

    size++;

    char** tokens = (char**) malloc(sizeof(char*) * size);

    i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            tokens[j] = (char*) malloc(sizeof(char) * (i - k + 1));

            for (int l = k; l < i; l++)
            {
                tokens[j][l - k] = str[l];
            }

            tokens[j][i - k] = '\0';

            k = i + 1;
            j++;
        }
        
        i++;
    }

    tokens[j] = (char*) malloc(sizeof(char) * (i - k + 1));

    for (int l = k; l < i; l++)
    {
        tokens[j][l - k] = str[l];
    }

    tokens[j][i - k] = '\0';

    *n = size;

    return tokens;
}

int main(){
    char str[] = " Texto de teste com várias palavras ";
    int size = 0;
    char** tokens = split(str, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", tokens[i]);
    }

    for (int i = 0; i < size; i++)
    {
        free(tokens[i]);
    }

    free(tokens);

    return 0;
}

// Texto
