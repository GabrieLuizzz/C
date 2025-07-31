#include <stdio.h>

void LerNotas(float *n1, float *n2) {
    printf("Digite a primeira nota: ");
    scanf("%f", n1);
    printf("Digite a segunda nota: ");
    scanf("%f", n2);
}

void CalcularMedias(float n1, float n2, float *mediaSimples, float *mediaPonderada) {
    *mediaSimples = (n1 + n2) / 2;
    *mediaPonderada = (n1 + 2 * n2) / 3;
}

int main() {
    float n1, n2;
    float mediaS, mediaP;

    LerNotas(&n1, &n2);
    CalcularMedias(n1, n2, &mediaS, &mediaP);

    printf("Media Simples: %.2f\n", mediaS);
    printf("Media Ponderada: %.2f\n", mediaP);

    return 0;
}
