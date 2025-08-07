#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *alocarString(int tam){
    char* str = (char *)malloc(tam+1 * sizeof(char));
    if(str == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    return str;
}
void SemVogais(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            printf("%c", str[i]);
        }
    }
}

int main() {
    int tam;
    char* texto;

    printf("Digite o tamanho da string: ");
    scanf("%d", &tam);
    getchar();

    texto = alocarString(tam);

    printf("Digite a string: ");
    fgets(texto, tam + 1, stdin);

    printf("String sem vogais: ");
    SemVogais(texto);

    free(texto);

    return 0;
}