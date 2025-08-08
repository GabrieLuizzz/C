#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_VETOR 1500

int main() {
    int *vetor_de_dados;
    int contador_zeros = 0;

    vetor_de_dados = (int *)calloc(TAMANHO_VETOR, sizeof(int));

    if (vetor_de_dados == NULL) {
        printf("Erro: Nao foi possivel alocar a memoria.\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (vetor_de_dados[i] == 0) {
            contador_zeros++;
        }
    }
    printf("O vetor foi inicializado com %d zeros.\n", contador_zeros);

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        vetor_de_dados[i] = i;
    }
    printf("\n--- Primeiros 10 elementos do vetor ---\n");
    for (int i = 0; i < 10; i++) {
        printf("Elemento[%d]: %d\n", i, vetor_de_dados[i]);
    }

    printf("\n--- Ultimos 10 elementos do vetor ---\n");
    for (int i = TAMANHO_VETOR - 10; i < TAMANHO_VETOR; i++) {
        printf("Elemento[%d]: %d\n", i, vetor_de_dados[i]);
    }
    free(vetor_de_dados);
    return 0;
}