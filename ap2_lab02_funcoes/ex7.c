#include <stdlib.h>
#include <stdio.h>

float converter(float c){
    return (c*9.0/5.0) + 32.0;
}

int main(){
    float celsius, fahrenheit;
    printf("Digite a temperatura em celsius: ");
    scanf("%f", &celsius);

    fahrenheit = converter(celsius);
    printf("Temperatura em fahrenheit: %.2f\n", fahrenheit);
    return 0;
}