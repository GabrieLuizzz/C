#include <stdio.h>

void SomaSemRetorno(int *x, int y) {
    *x = *x + y;
}

int main() {
    int A, B;

    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    SomaSemRetorno(&A, B);

    printf("Valor de A (apos a soma): %d\n", A);
    printf("Valor de B: %d\n", B);

    return 0;
}
