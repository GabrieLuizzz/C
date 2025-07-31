#include <stdio.h>

int main() {
    int array[5], *p, i;

    for (i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", (array + i));
    }

    for (p = array; p < array + 5; p++) {
        printf("Dobro: %d\n", (*p) * 2);
    }

    return 0;
}
