#include <stdlib.h>
#include <stdio.h>

int main() {
    int A, B;

    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    if(&A > &B){
        printf("O maior endereco eh de A: %p\n", (void*)&A);
        printf("O conteudo de A eh: %d\n", A);
    } else {
        printf("O maior endereco eh de B: %p\n", (void*)&B);
        printf("O conteudo de B eh: %d\n", B);
    }
    return 0;
}