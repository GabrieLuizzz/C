#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

float calcularVolumeCilindro(float raio, float altura){
    return PI*raio*raio*altura;
}
int main(){
    float raio, alt, vol;
    printf("Digite o raio do cilindro: ");
    scanf("%f", &raio);
    printf("Digite a altura do cilindro: ");
    scanf("%f", &alt);

    vol = calcularVolumeCilindro(raio, alt);
    printf("o volume do cilindro eh: %.2f\n", vol);
    return 0;
}
