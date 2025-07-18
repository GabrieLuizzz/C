#include <stdio.h>
#include <stdlib.h>

int transformar(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}
int main(){
    int h, m, s, totalsegundos;
    printf("Digite a hora (hh mm ss): ");
    scanf("%d %d %d", &h, &m, &s);

 totalsegundos = transformar(h, m, s);
    printf("Total de segundos: %d\n", totalsegundos);
    return 0;
}
