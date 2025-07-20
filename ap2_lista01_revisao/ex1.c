#include <stdio.h>
#include <stdlib.h>

int main(){
    float altura;

    printf("Digite a altura: ");
    if (scanf("%f", &altura) != 1){
        printf("Invalido, entre com um numero.\n");
        return 1;
    };

    if (altura <= 1.50){
        printf("Muito baixo!\n");
    } else if (altura <= 1.60){
        printf("Baixo!\n");
    } else if (altura <= 1.80){
        printf("Mediano!\n");
    } else if (altura > 1.80){
        printf("Alto!\n");
    } else {
        printf("Altura invalida!\n");
    }
}