// 10. Escreva uma função que receba um caminho de arquivo e retorna um vetor de strings contendo
// todas as palavras do arquivo. A string de separadores é passada como argumento à função. O
// número de palavras encontradas e colocadas no vetor de strings deve ser retornado via parâmetro
// words_count (por endereço). Caso ocorra algum problema, a função retorna NULL.
// char** get_words_sep(const char *path, const char* separators, int* words_count)
// Considerando exemplo do exercício anterior, este seria o retorno da função para
// os separadores " ,;.:?!-":
// {"C", "is", "a", "general-purpose", "programming", "language", "widely", "used",
// "and", "very", "influential", "By", "design", "C", "reflects", "the",
// "capabilities", "of", "the", "targeted", "CPUs", "such", "as", "types",
// "operations", "and", "memory", "access."}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_words_sep(const char *path, const char* separators, int* words_count){
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        return NULL;
    }
    
    char **words = NULL;
    char word[51];
    int i = 0, j = 0, count = 0;

    while (1)
    {
        char c = fgetc(file);
        if (c == EOF)
        {
            if (j > 0)
            {
                word[j] = '\0';
                words = (char**) realloc(words, (count + 1) * sizeof(char*));
                words[count] = (char*) malloc((j + 1) * sizeof(char));
                strcpy(words[count], word);
                count++;
                j = 0;
            }
            break;
        }
        if (strchr(separators, c) != NULL)
        {
            if (j > 0)
            {
                word[j] = '\0';
                words = (char**) realloc(words, (count + 1) * sizeof(char*));
                words[count] = (char*) malloc((j + 1) * sizeof(char));
                strcpy(words[count], word);
                count++;
                j = 0;
            }
        }
        else
        {
            word[j++] = c;
        }
    }
    *words_count = count;
    fclose(file);
    return words;
}

int main() {
    int words_count;
    char **res = get_words_sep("helloworld.txt", " ,;.:?!-", &words_count);
    if (res == NULL)
    {
        printf("ERRO arquivo nao encontrado");
        return 0;
    }
    for (int i = 0; i < words_count; i++)
    {
        printf("%s\n", res[i]);
    }
    return 0;
}