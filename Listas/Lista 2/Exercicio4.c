// 4. Escreva uma função que receba um caminho de arquivo e retorna a quantidade de linhas de texto
// contidas no arquivo. Dica: o caractere '\n' define a quebra de linha no texto.
// int count_lines(const char *filepath)

#include <stdio.h>
#include <stdlib.h>

int coint_lines(const char *filepath){
    FILE *file = fopen(filepath, "r");
    char ch = fgetc(file);
    int j = 1;

    while (ch != EOF)
    {
        ch = fgetc(file);
        if (ch == '\n')
        {
            j++;
        }
        
    }
    
    return j;
}

int main() {
    int res = coint_lines("helloworld.txt");
    printf("%d\n", res);
    return 0;
}