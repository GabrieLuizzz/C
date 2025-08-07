#include <stdio.h>
#include <stdlib.h>

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

    printf("\nVerificando se os elementos sao pares ou impares:\n");
    
    for(int i = 0; i < tam; i++) {
    if (vetor[i] % 2 == 0) {
            printf("Elemento %d (%d) eh PAR!\n", i + 1, vetor[i]);
    } else {
            printf("Elemento %d (%d) eh IMPAR!\n", i + 1, vetor[i]);
        }
    }

    free(vetor);
    return 0;
}