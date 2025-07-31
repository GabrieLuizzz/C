#include <stdio.h>
#include <stdlib.h>

int DobraESoma(int *a, int *b) {
    *a = *a * 2;
    *b = *b * 2;
    return *a + *b;
}

int main() {
    int A, B, result;

    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    result = DobraESoma(&A, &B);

    printf("Dobro de A: %d\n", A);
    printf("Dobro de B: %d\n", B);
    printf("Soma: %d\n", result);

    return 0;
}
