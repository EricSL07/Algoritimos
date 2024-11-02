// Escreva uma função que receba o endereço de uma string. A função deve retornar o endereço de
// uma cópia reversa da string alocada na heap.
// char* copy_reverse(const char* str)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* copy_reverse(const char* str){
    int tamanho = strlen(str);

    char* copia_reversa = (char*) malloc(sizeof(char) * (tamanho + 1));

    for (int i = 0; i < tamanho; i++)
    {
        copia_reversa[tamanho -i -1] = str[i];
    }

    copia_reversa[tamanho] = '\0';

    return copia_reversa;
    
}

int main(){
    char* string = "Hello World!";
    char* copia_reversa = copy_reverse(string);
    printf("%s\n", copia_reversa);
    free(copia_reversa);
    return 0;
}