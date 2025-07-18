#include <stdio.h>
#include <stdlib.h>

int verifica(int n) {
    if (n > 0)
        return 1;
    else if (n < 0)
        return -1;
    else
        return 0;
}

int main() {
    int num, resultado;
    
    printf("Digite um numero: ");
    scanf("%d", &num);

    resultado = verifica(num);

    printf("Resultado: %d\n", resultado);

    return 0;
}
