#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_BILHETE 6

int main() {
    int loteria[TAMANHO_BILHETE];
    int bilhete[TAMANHO_BILHETE];
    int *numeros_acertados = NULL;
    int contador_acertos = 0;

    printf("Digite os 6 numeros sorteados:\n");
    for (int i = 0; i < TAMANHO_BILHETE; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &loteria[i]);
    }

    printf("\nDigite os 6 numeros do seu bilhete:\n");
    for (int i = 0; i < TAMANHO_BILHETE; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &bilhete[i]);
    }

    for (int i = 0; i < TAMANHO_BILHETE; i++) {
        for (int j = 0; j < TAMANHO_BILHETE; j++) {
            if (bilhete[i] == loteria[j]) {
                contador_acertos++;
                break;
            }
        }
    }
    if (contador_acertos > 0) {
        numeros_acertados = (int *)malloc(contador_acertos * sizeof(int));
        if (numeros_acertados == NULL) {
            printf("Erro: Nao foi possivel alocar memoria para os numeros corretos.\n");
            return 1;
        }
        int k = 0;
        for (int i = 0; i < TAMANHO_BILHETE; i++) {
            for (int j = 0; j < TAMANHO_BILHETE; j++) {
                if (bilhete[i] == loteria[j]) {
                    numeros_acertados[k] = bilhete[i];
                    k++;
                    break;
                }
            }
        }
    }
    printf("\n--- Resultados ---\n");
    printf("Numeros sorteados: ");
    for (int i = 0; i < TAMANHO_BILHETE; i++) {
        printf("%d ", loteria[i]);
    }
    printf("\n");
    if (contador_acertos > 0) {
        printf("Voce acertou %d numero(s).\n", contador_acertos);
        printf("Seus numeros corretos sao: ");
        for (int i = 0; i < contador_acertos; i++) {
            printf("%d ", numeros_acertados[i]);
        }
        printf("\n");
    } else {
        printf("Voce nao acertou nenhum numero.\n");
    }
    if (numeros_acertados != NULL) {
        free(numeros_acertados);
    }
    return 0;
}