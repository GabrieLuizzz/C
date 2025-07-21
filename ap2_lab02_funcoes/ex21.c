#include <stdio.h>
#include <stdlib.h>

void exclamacoes(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            printf("!");
        }
        printf("\n");
    }
}

int main() {
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    exclamacoes(num);

    return 0;
}
