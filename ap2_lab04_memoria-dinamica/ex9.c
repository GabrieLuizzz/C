#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = NULL, num;
    int tam = 0;

    printf("Digite uma sequencia de numeros (digite um numero negativo para parar):\n");

    while (1) {
        printf("Numero: ");
        scanf("%d", &num);

        if (num < 0) {
            break;
        }
        tam++;

        vetor = (int *)realloc(vetor, tam * sizeof(int));

        if (vetor == NULL) {
            printf("Erro: Nao foi possivel realocar a memoria.\n");
            return 1;
        }
        vetor[tam - 1] = num;
    }
    if (tam > 0) {
        printf("\nVetor lido:\n");
        for (int i = 0; i < tam; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
    } else {
        printf("\nNenhum numero positivo foi digitado.\n");
    }
    if (vetor != NULL) {
        free(vetor);
    }

    return 0;
}