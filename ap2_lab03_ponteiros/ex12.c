#include <stdio.h>

void frac(float num, int *inteiro, float *frac) {
    *inteiro = (int)num;
    *frac = num - *inteiro;
}

int main() {
    float num, partFracionaria;
    int partInteira;

    printf("Digite um numero real: ");
    scanf("%f", &num);

    frac(num, &partInteira, &partFracionaria);

    printf("Parte inteira: %d\n", partInteira);
    printf("Parte fracionária: %.2f\n", partFracionaria);

    return 0;
}
