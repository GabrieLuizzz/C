#include <stdio.h>
#include <stdlib.h>

int main(){
    int var1 = 10, var2 = 15, *p1, *p2;

    printf("Endereco de var1: %p\n", &var1);
    printf("Endereco de var2: %p\n", &var2);

    if(&var1 > &var2){
        printf("Maior endereco: %p\n", &var1);
    } else {
        printf("Maior endereco: %p\n", &var2);
    }
    return 0;
}