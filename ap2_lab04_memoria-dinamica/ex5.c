#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, *vetor, i, contador = 0;

    printf("Digite o tamanho do vetor (N): ");
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor de X: ");
    scanf("%d", &x);

    printf("Multiplos de %d no vetor:\n", x);
    for (i = 0; i < n; i++) {
        if (vetor[i] % x == 0) {
            printf("%d ", vetor[i]);
            contador++;
        }
    }
    printf("\nQuantidade de multiplos de %d: %d\n", x, contador);

    free(vetor);

    return 0;
}
