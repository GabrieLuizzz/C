#include <stdlib.h>
#include <stdio.h>

int main() {
    int *array;
    int i;

    array = (int *)malloc(5 * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite 5 numeros inteiros:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Os numeros digitados foram:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    free(array);
    
    return 0;
}