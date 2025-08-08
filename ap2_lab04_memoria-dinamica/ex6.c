#include <stdio.h>
#include <stdlib.h>

int main() {
    int *memoria, tam_bytes, op, pos, val;
    int tam_int = sizeof(int);

    printf("Digite o tamanho da memoria em bytes (deve ser um multiplo de %d do tamanho de um inteiro): ", tam_int);
    scanf("%d", &tam_bytes);

    if (tam_bytes % tam_int != 0) {
        printf("Erro: O tamanho da memoria nao e um multiplo do tamanho de um inteiro.\n");
        return 1;
    }

    int num_elementos = tam_bytes / tam_int;
    memoria = (int *)calloc(num_elementos, tam_int);

    if (memoria == NULL) {
        printf("Erro: Nao foi possivel alocar a memoria.\n");
        return 1;
    }

    do {
        printf("\n--- Simulador de Memoria ---\n");
        printf("1. Inserir um valor em uma posicao\n");
        printf("2. Consultar o valor de uma posicao\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite a posicao (0 a %d): ", num_elementos - 1);
                scanf("%d", &pos);

                if (pos >= 0 && pos < num_elementos) {
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &val);
                    memoria[pos] = val;
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Erro: Posicao invalida.\n");
                }
                break;

            case 2:
                printf("Digite a posicao para consulta (0 a %d): ", num_elementos - 1);
                scanf("%d", &pos);

                if (pos >= 0 && pos < num_elementos) {
                    printf("O valor na posicao %d eh: %d\n", pos, memoria[pos]);
                } else {
                    printf("Erro: Posicao invalida.\n");
                }
                break;

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (op != 3);

    free(memoria);
    return 0;
}