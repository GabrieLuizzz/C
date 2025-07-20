#include <stdio.h>
#include <stdlib.h>

int somadealgarismos(int n){
    if(n>0){
        return n%10 + somadealgarismos(n/10);
    } else if(n==0) {
        return 0;
    } else {
        printf("Numero invalido.\n");
        return 0;
    }
}
int main(){
    int n, soma;

    printf("Digite um numero: ");
    scanf("%d", &n); 

    soma = somadealgarismos(n);
    if(soma>=0){
        printf("A soma dos algarismos eh: %d\n", soma);
    } 
}