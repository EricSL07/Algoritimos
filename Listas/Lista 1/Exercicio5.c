#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat_string(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int total_len = len1 + len2 + 1; // +1 for null terminator

    char* result = (char*)malloc(total_len * sizeof(char));
    if (result == NULL) {
        // Handle allocation failure
        perror("Memory allocation failed");
        exit(1);
    }

    // Copy the first string
    strncpy(result, str1, len1);

    // Copy the second string, starting from the end of the first
    strncpy(result + len1, str2, len2);

    // Add the null terminator
    result[total_len - 1] = '\0';

    return result;
}

int main() {
    char* str1 = "Hello, ";
    char* str2 = "world!";
    char* result = concat_string(str1, str2);

    printf("%s\n", result);

    free(result);

    return 0;
}