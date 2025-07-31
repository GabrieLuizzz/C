#include <stdio.h>
#include <stdlib.h>

void Ordenar(int *a, int *b) {
    if (*b > *a) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    int x, y;

    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);

    Ordenar(&x, &y);

    printf("Maior valor: %d\n", x);
    printf("Menor valor: %d\n", y);

    return 0;
}