#include <stdlib.h>
#include <stdio.h>

int somaentrenumeros(int n1, int n2){
    int soma = 0;

    if(n1>n2){
        int temp=n1;
        n1=n2;
        n2=temp;
    }
    for(int i=n1+1; i<n2; i++){
        soma+=i;
    }
    return soma;
}
int main(){
    int n1, n2, result;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);
    
    result = somaentrenumeros(n1,n2);

    printf("A soma dos numeros entre %d e %d eh: %d\n", n1, n2, result);
    return 0;
}