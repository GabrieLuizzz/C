#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularhipotenusa(float a, float b){
    return sqrt(a*a + b*b);
}
int main(){
    float cat1, cat2, hip;
    printf("Digite o cateto 1: ");
    scanf("%f", &cat1);
    printf("Digite o cateto 2: ");
    scanf("%f", &cat2);

    hip = calcularhipotenusa(cat1, cat2);
    printf("A hipotenusa eh: %.2f\n", hip);
    return 0;
}
