#include <stdio.h>
#include <stdlib.h>

int calcularfatorial(int n){
    int fatorial;
    if(n<0){
        printf("Fatorial nao existe.\n");
        return -1;
    } else if (n==0 || n==1){
        return 1;
    } else {
        fatorial =1;
        for(int i=2; i<=n; i++){
            fatorial*=i;
        }
    }
return fatorial;
}
int main(){
    int n, fatorial;

    printf("Digite um numero: ");
    scanf("%d", &n);

    fatorial = calcularfatorial(n);

    if(fatorial == -1){
        return 0;
    }
    printf("O fatorial de %d eh: %d\n", n, fatorial);
    return 0;
}