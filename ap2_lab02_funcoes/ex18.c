#include <stdio.h>
#include <stdlib.h>

int elevado(int x, int z){
    int resultado = 1;
    for(int i=0; i<z; i++){
        resultado*=x;
    }
    return resultado;
}
int main(){
    int base, expoente, result;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    result = elevado(base, expoente);
    
    printf("%d elevado a %d eh: %d\n", base, expoente, result);
    return 0;
}