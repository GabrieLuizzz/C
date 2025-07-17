#include <stdio.h>
#include <stdlib.h>

int quadrado(int x){
    return x * 2;
}
int main (void) {
    int n1,n2;
    printf("Digite um numero: ");
    scanf("%d", &n1);

    n2 = quadrado(n1);

    printf("O quadrado de %d eh %d\n", n1, n2);
    return 0;
}