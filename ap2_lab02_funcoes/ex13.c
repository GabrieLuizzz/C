#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fazerOperacao(int n1, int n2, char op){
    if(op == '+')
        return n1+n2;
    else if(op == '-')
        return n1-n2;
    else if(op == '*')
        return n1*n2;
    else if(op == '/')
        return n1/n2;
    else
        return 0;
}

int main(){
    int n1, n2, result;
    char op;

    printf("Digite um numero: ");
    scanf("%d", &n1);
    printf("Digite outro numero: ");
    scanf("%d", &n2);
    printf("Digite a operacao que sera feita (+, -, *, /): ");
    scanf(" %c", &op);

    result = fazerOperacao(n1, n2, op);
    
    if(op == '/' || op == '+' || op == '-' || op == '*'){
        printf("O resultado da operacao eh: %d\n", result);
    } else {
        printf("Operacao invalida.\n");
    }
}