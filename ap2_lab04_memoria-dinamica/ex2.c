#include <stdlib.h>
#include <stdio.h>

int main() {
    int *vetor, tam;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = (int *)malloc(tam * sizeof(int));

    if(vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for(int i = 0; i < tam; i++) {
        printf("Digite o valor do elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
        printf("\nVetor lido: \n");

    for(int i=0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}