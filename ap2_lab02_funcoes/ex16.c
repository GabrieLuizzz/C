#include <stdlib.h>
#include <stdio.h>

void desenha_linha(int quantidade, int i){
    for(i = 0; i<quantidade; i++){
        printf("=");
    }
}
int main(){
    int n;
    printf("Quantidade de sinais ('='): ");
    scanf("%d", &n);

    desenha_linha(n, 0);

    return 0;
}