#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula, ano_nasc;
    char sobrenome[50];
} Aluno;

int main() {
    int n_alunos;
    Aluno *vet_alunos;

    printf("Digite o numero de alunos a serem cadastrados: ");
    scanf("%d", &n_alunos);

    vet_alunos = (Aluno *)malloc(n_alunos * sizeof(Aluno));

    if (vet_alunos == NULL) {
        printf("Erro: Nao foi possivel alocar a memoria.\n");
        return 1;
    }

    for (int i = 0; i < n_alunos; i++) {
        printf("\n--- Cadastro do Aluno %d ---\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &vet_alunos[i].matricula);

        printf("Sobrenome: ");
        scanf("%s", vet_alunos[i].sobrenome);

        printf("Ano de nascimento: ");
        scanf("%d", &vet_alunos[i].ano_nasc);
    }

    printf("\n--- Dados dos Alunos Cadastrados ---\n");
    for (int i = 0; i < n_alunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Matricula: %d\n", vet_alunos[i].matricula);
        printf("Sobrenome: %s\n", vet_alunos[i].sobrenome);
        printf("Ano de nascimento: %d\n", vet_alunos[i].ano_nasc);
    }

    free(vet_alunos);
    return 0;
}