#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod, quantidade;
    char nome[51];
    double preco;
} Produto;

int main() {
    int N;
    Produto *estoque;
    int indice_maior_preco = -1;
    int indice_maior_quantidade = -1;

    printf("Digite o numero de produtos a serem cadastrados: ");
    scanf("%d", &N);

    estoque = (Produto *)malloc(N * sizeof(Produto));

    if (estoque == NULL) {
        printf("Erro: Nao foi possivel alocar a memoria.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("\n--- Cadastro do Produto %d ---\n", i + 1);
        printf("Codigo de identificacao: ");
        scanf("%d", &estoque[i].cod);
        printf("Nome do produto: ");
        scanf(" %50[^\n]", estoque[i].nome);
        printf("Quantidade disponivel: ");
        scanf("%d", &estoque[i].quantidade);
        printf("Preco de venda: ");
        scanf("%lf", &estoque[i].preco);
    }
    if (N > 0) {
        double maior_preco = estoque[0].preco;
        indice_maior_preco = 0;
        for (int i = 1; i < N; i++) {
            if (estoque[i].preco > maior_preco) {
                maior_preco = estoque[i].preco;
                indice_maior_preco = i;
            }
        }
    }
    if (N > 0) {
        int maior_quantidade = estoque[0].quantidade;
        indice_maior_quantidade = 0;
        for (int i = 1; i < N; i++) {
            if (estoque[i].quantidade > maior_quantidade) {
                maior_quantidade = estoque[i].quantidade;
                indice_maior_quantidade = i;
            }
        }
    }
    printf("\n--- Resultados ---\n");
    if (indice_maior_preco != -1) {
        printf("Produto com o maior preco de venda:\n");
        printf("Nome: %s\n", estoque[indice_maior_preco].nome);
        printf("Preco: %.2f\n", estoque[indice_maior_preco].preco);
    } else {
        printf("Nenhum produto cadastrado para encontrar o maior preco.\n");
    }
    
    if (indice_maior_quantidade != -1) {
        printf("\nProduto com a maior quantidade disponivel:\n");
        printf("Nome: %s\n", estoque[indice_maior_quantidade].nome);
        printf("Quantidade: %d\n", estoque[indice_maior_quantidade].quantidade);
    } else {
        printf("Nenhum produto cadastrado para encontrar a maior quantidade.\n");
    }
    free(estoque);
    return 0;
}