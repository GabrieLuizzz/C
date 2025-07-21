#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float determinarTriangulo(float a, float b, float c){
    if (a+b > c && a+c > b && b+c > a){
        if (a==b && b==c){
            return 1;
        }
        else if(a==b || b==c || a==c){
            return 2;
        }
        else {
            return 3;
        }
    }
    return 0;
}
int main(){
    float a, b, c, tipo;
    
    printf("Digite o lado A: ");
    scanf("%f", &a);
    printf("Digite o lado B: ");
    scanf("%f", &b);
    printf("Digite o lado C: ");
    scanf("%f", &c);

    tipo = determinarTriangulo(a, b, c);

    if (tipo==1){
        printf("O triangulo eh Equilatero!\n");
    } else if (tipo==2){
        printf("O triangulo eh Isosceles!\n");
    } else if (tipo==3){
        printf("O triangulo eh Escaleno!\n");
    } else {
        printf("Nao eh um triangulo!\n");
    }
}