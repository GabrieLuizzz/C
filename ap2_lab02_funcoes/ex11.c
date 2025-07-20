#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularNotaAluno(float n1, float n2, float n3, char tipo){
    if (tipo == 'A' || tipo == 'a')
        return(n1+n2+n3)/3;
    else if(tipo == 'P' || tipo == 'p')
        return(5*n1 + 3*n2 + 2*n3)/10;
    else
        return 0;
}
int main(){
    float n1, n2, n3, media;
    char tipo;
    
    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);
    printf("Digite o tipo de media (A para Aritmetica, P para Ponderada): ");
    scanf(" %c", &tipo);
    
    media = calcularNotaAluno(n1, n2, n3, tipo);
    
    if (media>=0)
        printf("A media do aluno eh: %.2f\n", media);
    else
        printf("Media invalida.\n");
    return 0;
}