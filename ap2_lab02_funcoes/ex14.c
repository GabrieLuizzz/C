#include <stdio.h>
#include <stdlib.h>

float calculargasolina(float distancia, float consumo){
    if(consumo < 8){
        printf("Venda o carro!\n");
    } else if(consumo >= 8 && consumo <= 14){
        printf("Economico!\n");
    } else {
        printf("Super economico!\n");
    }

    return distancia/consumo;
}

int main(){
    float distancia, consumo, result;

    printf("Distancia percorrida: ");
    scanf("%f", &distancia);
    printf("Consumo do carro (km/L): ");
    scanf("%f", &consumo);

    result = calculargasolina(distancia, consumo);
   
    printf("Quantidade de litros usados: %.2f\n", result);

    return 0;
}
