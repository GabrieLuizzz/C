#include <stdio.h>

int main() {
    int array[5], *p, i;

    for (i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (p = array; p < array + 5; p++) {
        if (*p % 2 == 0) {
            printf("Valor par: %d\n localizado no endereco: %p\n", *p, (void *)p);
        }
    }

    return 0;
}
