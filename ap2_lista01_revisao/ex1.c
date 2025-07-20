#include <stdio.h>
#include <stdlib.h>

int main(){
    float altura;

    printf("Digite a altura: ");
    scanf("%f", &altura);

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