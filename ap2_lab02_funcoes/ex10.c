#include <stdio.h>
#include <stdlib.h>

int verificarNumeroMaior(int n1, int n2){
    if(n1>n2){
        return n1;
    } else {
        return n2;
    }
}
int main(){
    int n1, n2, maior;
    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    maior = verificarNumeroMaior(n1, n2);
    printf("O maior numero eh: %d\n", maior);
    return 0;
}