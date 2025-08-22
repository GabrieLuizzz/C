#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int array[], int chave, int tam) {
    int i;
    for(i=0; i < tam; i++) {
        if(array[i] == chave) {
            return i;
        }
    }
    return -1;
}
int main() {
    int array[] = {1, 2, 3, 4, 5};
    int chave = 3;
    int tam = sizeof(array) / sizeof(array[0]);
    int result = busca_sequencial(array, chave, tam);

    if(result != -1) {
        printf("Chave encontrada no indice: %d\n", result);
    } else {
        printf("Chave não encontrada!\n");  
    }
    return 0;
}