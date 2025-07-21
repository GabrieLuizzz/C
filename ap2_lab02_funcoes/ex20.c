#include <stdio.h>
#include <stdlib.h>

int primo(int n) {
    if (n<2) 
    return 0;

    for(int i=2; i*i <= n; i++) {
        if (n % i==0) {
            return 0;
        }
    }
    return 1;
}
int quantidadePrimosAbaixo(int num) {
    int cont = 0;

    for (int i=2; i<num; i++) {
        if (primo(i)) {
            cont++;
        }
    }

    return cont;
}

int main() {
    int n;

    printf("Digite um valor: ");
    scanf("%d", &n);

    int totalprimos = quantidadePrimosAbaixo(n);
    printf("Quantidade de numeros primos abaixo de %d: %d\n", n, totalprimos);

    return 0;
}
