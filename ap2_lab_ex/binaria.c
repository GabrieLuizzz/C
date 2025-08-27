#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int array[], int chave, int tam) {
    int ini = 0;
    int fim = tam - 1;

    while(ini <= fim) {
        int meio = ini + (fim - ini) / 2;

        if(array[meio] == chave) {
            return meio;
        }
        else if(array[meio] < chave) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}