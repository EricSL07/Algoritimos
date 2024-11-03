// 8. Escreva uma função que receba um caminho de arquivo e retorna uma string (vetor de caracteres
// terminado em nulo) alocada em heap contendo o conteúdo do arquivo. Caso ocorra algum
// problema, retorna NULL.
// char* get_content(const char *filepath)

#include <stdio.h>
#include <stdlib.h>

char* get_content(const char *filepath){
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        return NULL;
    }
    
    char *content = (char*) malloc(1000 * sizeof(char));
    int i = 0;
    while (1)
    {
        char c = fgetc(file);
        if (c == EOF)
        {
            break;
        }
        content[i] = c;
        i++;
    }
    content[i] = '\0';
    fclose(file);
    return content;
}

int main() {
    char *res = get_content("helloworld.txt");
    if (res == NULL)
    {
        printf("ERRO arquivo nao encontrado");
        return 0;
    }
    printf("%s\n", res);
    free(res);
    return 0;
}