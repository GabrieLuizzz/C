#include <stdio.h>
#include <stdlib.h>

void triangulo(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n-i; j++) {
            printf(" ");
        }
        for (int k=1; k<=2*i-1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int num;

    printf("Digite o valor de n: ");
    scanf("%d", &num);

    triangulo(num);

    return 0;
}