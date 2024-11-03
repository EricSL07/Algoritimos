// 3. Escreva uma função que receba um caminho de arquivo e imprima seu conteúdo no terminal.
// Retorna 1 para sucesso ou 0, caso o arquivo não exista.
// int print_content(const char *filepath)

#include <stdio.h>
#include <stdlib.h>

int print_content(const char *filepath){
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        return 0;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }
    
    fclose(file);
    return 1;
}

int main() {
    print_content("helloworld.txt");
    return 0;
}