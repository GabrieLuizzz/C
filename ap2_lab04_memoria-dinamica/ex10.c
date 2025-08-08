#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_MINIMO 10

int main() {
    double *v_doubles;
    int tam_desejado;

    srand(time(NULL));

    do {
        printf("Quantos valores 'double' deseja armazenar? (O tamanho deve ser maior ou igual a %d): ", TAMANHO_MINIMO);
        scanf("%d", &tam_desejado);
        if (tam_desejado < TAMANHO_MINIMO) {
            printf("Erro: O tamanho deve ser maior ou igual a %d. Tente novamente.\n", TAMANHO_MINIMO);
        }
    } while (tam_desejado < TAMANHO_MINIMO);

    v_doubles = (double *)malloc(tam_desejado * sizeof(double));

    if (v_doubles == NULL) {
        printf("Erro: Nao foi possivel alocar a memoria.\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_MINIMO; i++) {
        v_doubles[i] = (double)rand() / (RAND_MAX / 100.0);
    }

    printf("\n--- Valores dos 10 primeiros elementos do vetor ---\n");
    for (int i = 0; i < TAMANHO_MINIMO; i++) {
        printf("Elemento[%d]: %.2f\n", i, v_doubles[i]);
    }

    free(v_doubles);
    return 0;
}