#include <stdio.h>
#include <stdlib.h>

void TrocaValores(int *A, int *B){
    int temp;
    temp = *A;
    *A = *B;
    *B = temp;
}
int main(){
    int A, B;
    
    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    TrocaValores(&A, &B);

    printf("Valor de A depois da troca: %d\n", A);
    printf("Valor de B depois da troca: %d\n", B);

    return 0;
}