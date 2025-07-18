#include <stdio.h>
#include <stdlib.h>

int quadradoperfeito(int n){
    int i;
    for(i = 0; i <= n; i++){
        if(i * i == n){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    if (quadradoperfeito(n)){
        printf("O numero %d eh um quadrado perfeito.\n", n);
    } else {
        printf("O numero %d nao eh um quadrado perfeito.\n", n);
    };
}