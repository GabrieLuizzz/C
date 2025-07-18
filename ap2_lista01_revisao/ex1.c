#include <stdio.h>
#include <stdlib.h>

int main(){
    float altura;

    printf("Digite a altura: ");
    scanf("%f", &altura);

    if (altura <= 1.50){
        printf("Muito baixo!\n");
    } else if (1.50 < altura && altura <= 1.60){
        printf("Baixo!\n");
    } else if (1.60 < altura && altura <= 1.80){
        printf("Mediano!\n");
    } else if (1.80 < altura){
        printf("Alto!\n");
    } else {
        printf("Altura invalida!\n");
    }
}