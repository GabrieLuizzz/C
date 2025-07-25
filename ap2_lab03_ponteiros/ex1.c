#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 10, *ponteirox;
    float y = 5.0, *ponteiroy;
    char z = 'A', *ponteiroz;
    
    ponteirox = &x;
    ponteiroy = &y;
    ponteiroz = &z;

    printf("_ANTES DA MODIFICACAO_\n");
    printf("Valor de x: %d\n", *ponteirox);
    printf("Valor de y: %.2f\n", *ponteiroy);
    printf("Valor de z: %c\n", *ponteiroz);

    *ponteirox = 20;
    *ponteiroy = 10.5;
    *ponteiroz = 'B';

    printf("_DEPOIS DA MODIFICACAO_\n");
    printf("Valor de x: %d\n", *ponteirox);
    printf("Valor de y: %.2f\n", *ponteiroy);
    printf("Valor de z: %c\n", *ponteiroz);
}