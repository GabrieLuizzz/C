#include <stdio.h>
#include <stdlib.h>

void dataatualporextenso(int dia, int mes, int ano)
{
    char *meses[] = {"", "janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
                "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    if(mes < 1 || mes > 12) 
        {
        printf("Mes invalido!\n");
        return;
        }
    printf("Data: %d de %s de %d\n", dia, meses[mes], ano);
}
int main()
{
    int dia,mes,ano;
    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o mes: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);

    dataatualporextenso(dia, mes, ano);
    return 0;
}
