// 6. Escreva uma função que receba um caminho de arquivo e acrescenta uma string no mesmo. A
// função deve criar o arquivo especificado, caso não exista. Retorna 1 para sucesso ou 0, em caso
// de erro. Dica: observe o modo de abertura 'a' (slide no. 5 do material).
// int append_string(const char *filepath, const char* text)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append_string(const char *filepath, const char* text){
    FILE *file = fopen(filepath, "a");
    if (file == NULL)
    {
        fclose(file);
        return 0 ;
    }
    

    for (int i = 0; text[i] != '\0'; i++)
    {
        fputc(text[i], file);
    }
    
    fclose(file);
    return 1;
}

int main() {
    int res = append_string("helloworld.txt", "\nHello World");
    printf("%d\n", res);
    return 0;
}
