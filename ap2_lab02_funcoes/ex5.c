#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14

float volumeesfera(float raio){
    return (4.0/3.0) *M_PI* pow(raio, 3);
}
int main(){
    float raio;
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    printf("O volume da esfera eh: %.2f\n", volumeesfera(raio));
    return 0;
}