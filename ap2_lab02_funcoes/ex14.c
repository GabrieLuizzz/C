#include <stdio.h>
#include <stdlib.h>

int calculargasolina(int distancia, int consumo){
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
    int distancia, consumo, result;

    printf("Distancia percorrida: ");
    scanf("%d", &distancia);
    printf("Consumo do carro (km/L): ");
    scanf("%d", &consumo);

    result = calculargasolina(distancia, consumo);
   
    printf("Quantidade de litros usados: %d\n", result);

    return 0;
}
