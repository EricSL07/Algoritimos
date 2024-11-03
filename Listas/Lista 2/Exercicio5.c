// 5. Escreva uma função que receba um caminho de arquivo e escreva uma string no mesmo. A função
// deve (re)criar o arquivo especificado. Retorna 1 para sucesso ou 0, em caso de erro.
// int save_string(const char *filepath, const char* text)

#include <stdio.h>
#include <stdlib.h>

int save_string(const char *filepath, const char* text){
    FILE *file = fopen(filepath, "w+");
    if (file == NULL)
    {
        printf("ERRO arquivo nao encontrado");
        return 0;
    }
    
    for (int i = 0; text[i] != '\0'; i++)
    {
        fputc(text[i], file);
    }

    fclose(file);
    
    
}

int main() {
    int res = save_string("helloworld.txt", "Hello World");
    printf("%d\n", res);
    return 0;
}