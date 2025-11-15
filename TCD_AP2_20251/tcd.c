#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME 256

// Variáveis globais
int *dados = NULL;
int tamanho = 0;
int ordenado = 0;
int algum_algoritmo_executado = 0;

// Funções auxiliares
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int encontrar_max(int arr[], int n) {
    if (n <= 0) return 0;
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int encontrar_min(int arr[], int n) {
    if (n <= 0) return 0;
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

void liberar_memoria() {
    if (dados) {
        free(dados);
        dados = NULL;
    }
    tamanho = 0;
    ordenado = 0;
    algum_algoritmo_executado = 0;
}

// Função para verificar se o vetor está ordenado
int verificar_ordenacao(int arr[], int n) {
    if (n <= 1) return 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Algoritmos de ordenação
void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        trocar(&arr[min_idx], &arr[i]);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void counting_sort(int arr[], int n) {
    if (n <= 1) return;
    int max = encontrar_max(arr, n);
    int min = encontrar_min(arr, n);
    
    int range = max - min + 1;
    int *count = (int*)calloc(range, sizeof(int));
    int *output = (int*)malloc(n * sizeof(int));
    
    if (!count || !output) {
        printf("Erro de memoria na ordenacao!\n");
        if (count) free(count);
        if (output) free(output);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    free(count);
    free(output);
}


// Funções principais
void carregar_arquivo() {
    char filename[MAX_FILENAME];
    FILE *fp;
    int num, count = 0, capacity = 100;
    
    liberar_memoria();
    
    printf("\n--- Carregar Arquivo de Dados ---\n");
    printf("Digite o nome do arquivo (ex: dados.txt): ");
    scanf("%s", filename);
    
    fp = fopen(filename, "r");
    if (!fp) {
        printf("\nERRO: Arquivo '%s' nao encontrado!\n", filename);
        printf("Certifique-se de que o arquivo existe na mesma pasta do programa.\n");
        return;
    }
    
    dados = (int*) malloc(capacity * sizeof(int));
    if (!dados) {
        printf("Erro de memoria!\n");
        fclose(fp);
        return;
    }
    
    while (fscanf(fp, "%d", &num) == 1) {
        if (count >= capacity) {
            capacity *= 2;
            int *tmp = (int*)realloc(dados, capacity * sizeof(int));
            if (!tmp) {
                printf("Erro de memoria durante expansao!\n");
                free(dados);
                dados = NULL;
                fclose(fp);
                return;
            }
            dados = tmp;
        }
        dados[count++] = num;
    }
    
    fclose(fp);
    tamanho = count;
    ordenado = verificar_ordenacao(dados, tamanho); // Verifica se o vetor já está ordenado ao carregar
    
    printf("%d elementos carregados com sucesso do arquivo '%s'!\n", tamanho, filename);
    printf("O vetor %s.\n", ordenado ? "esta ordenado" : "nao esta ordenado");
}

void buscar_elemento() {
    if (!dados) {
        printf("Nenhum arquivo carregado. Por favor, carregue um arquivo primeiro (opcao 1).\n");
        return;
    }

    int tipo, valor, i, pos = -1;
    clock_t inicio, fim;
    double tempo;

    printf("\n--- Submenu de Busca ---\n");
    printf("1. Busca Linear\n");
    printf("2. Busca Binaria\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &tipo);

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    if (tipo == 1) {
        inicio = clock();
        for (i = 0; i < tamanho; i++) {
            if (dados[i] == valor) {
                pos = i;
                break;
            }
        }
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;
        
        if (pos != -1) {
            printf("Elemento %d encontrado na posicao %d.\n", valor, pos);
        } else {
            printf("Elemento %d nao encontrado.\n", valor);
        }
        printf("Tempo de execucao: %.10f ms\n", tempo);

    } else if (tipo == 2) {
        if (!ordenado) {
            printf("\nERRO: A busca binaria so funciona em dados ordenados.\n");
            printf("Ordene os dados primeiro (opcao 3).\n");
            return;
        }
        
        int esq = 0, dir = tamanho - 1, meio;
        inicio = clock();
        while (esq <= dir) {
            meio = esq + (dir - esq) / 2;
            if (dados[meio] == valor) {
                pos = meio;
                break;
            } else if (dados[meio] < valor) {
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;
        
        if (pos != -1) {
            printf("Elemento %d encontrado na posicao %d.\n", valor, pos);
        } else {
            printf("Elemento %d nao encontrado.\n", valor);
        }
        printf("Tempo de execucao: %.10f ms\n", tempo);

    } else {
        printf("Opcao de busca invalida!\n");
    }
}

void ordenar_dados() {
    if (!dados) {
        printf("Nenhum arquivo carregado. Por favor, carregue um arquivo primeiro (opcao 1).\n");
        return;
    }
    
    int opcao;
    int *copia = (int*)malloc(tamanho * sizeof(int));
    if (!copia) {
        printf("Erro de memoria!\n");
        return;
    }
    
    copiar_vetor(dados, copia, tamanho);
    
    printf("\n--- Submenu de Ordenacao ---\n");
    printf("1. Insertion Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Algoritmo EXTRA (Counting Sort)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    clock_t inicio = clock();
    
    switch(opcao) {
        case 1:
            insertion_sort(copia, tamanho);
            break;
        case 2:
            bubble_sort(copia, tamanho);
            break;
        case 3:
            selection_sort(copia, tamanho);
            break;
        case 4:
            merge_sort(copia, 0, tamanho - 1);
            break;
        case 5:
            quick_sort(copia, 0, tamanho - 1);
            break;
        case 6:
            counting_sort(copia, tamanho);
            break;
        default:
            printf("Opcao invalida!\n");
            free(copia);
            return;
    }
    
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;
    
    printf("\nOrdenacao concluida.\n");
    printf("Tempo de execucao: %.10f ms\n", tempo);
    
    // Substituir dados originais pelos ordenados
    free(dados);
    dados = copia;
    ordenado = 1; // O vetor agora está ordenado
    algum_algoritmo_executado = 1;
    
    char salvar;
    printf("Deseja salvar o vetor ordenado em um novo arquivo? (s/n): ");
    scanf(" %c", &salvar);
    if (salvar == 's' || salvar == 'S') {
        char arquivo[MAX_FILENAME];
        printf("Nome do arquivo para salvar (ex: dados_ordenados.txt): ");
        scanf("%s", arquivo);
        FILE *fp = fopen(arquivo, "w");
        if (fp) {
            for (int i = 0; i < tamanho; i++) {
                fprintf(fp, "%d\n", dados[i]);
            }
            fclose(fp);
            printf("Vetor ordenado salvo em '%s' com sucesso!\n", arquivo);
        } else {
            printf("Erro ao salvar arquivo!\n");
        }
    }
}

void gerar_relatorio() {
    if (!algum_algoritmo_executado) {
        printf("Nenhum algoritmo foi executado ainda. Por favor, execute uma ordenacao ou busca primeiro.\n");
        return;
    }
    
    FILE *fp = fopen("relatorio.txt", "w");
    if (!fp) {
        printf("Erro ao criar arquivo de relatorio!\n");
        return;
    }
    
    fprintf(fp, "RELATORIO DE DESEMPENHO\n");
    fprintf(fp, "-----------------------\n");
    fprintf(fp, "Tamanho do vetor: %d elementos\n", tamanho);
    fprintf(fp, "Data/Hora: %s\n", ctime(&(time_t){time(NULL)}));
    
    // Executar cada algoritmo 100 vezes e calcular a média
    fprintf(fp, "\nTEMPOS DE ORDENACAO (media de 100 execucoes):\n");
    fprintf(fp, "-----------------------------------------\n");
    
    char *nomes_algoritmos[] = {"Insertion Sort", "Bubble Sort", "Selection Sort", 
                                "Merge Sort", "Quick Sort", "Counting Sort (EXTRA)"};
    
    for (int alg = 0; alg < 6; alg++) {
        double tempo_total = 0.0;
        for (int exec = 0; exec < 100; exec++) {
            int *copia = (int*)malloc(tamanho * sizeof(int));
            if (!copia) {
                fclose(fp);
                printf("Erro de memoria para gerar relatorio!\n");
                return;
            }
            copiar_vetor(dados, copia, tamanho);
            
            clock_t inicio = clock();
            switch(alg) {
                case 0: insertion_sort(copia, tamanho); break;
                case 1: bubble_sort(copia, tamanho); break;
                case 2: selection_sort(copia, tamanho); break;
                case 3: merge_sort(copia, 0, tamanho - 1); break;
                case 4: quick_sort(copia, 0, tamanho - 1); break;
                case 5: counting_sort(copia, tamanho); break;
            }
            clock_t fim = clock();
            tempo_total += (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;
            free(copia);
        }
        double media = tempo_total / 100.0;
        fprintf(fp, "%s: %.10f ms\n", nomes_algoritmos[alg], media);
    }
    
    // Comparação de buscas
    fprintf(fp, "\nCOMPARACAO DE BUSCAS:\n");
    fprintf(fp, "--------------------\n");
    
    // Para a busca binária, o vetor deve estar ordenado
    if (ordenado) {
        int valor_busca = dados[tamanho / 2]; // Buscar um valor que existe
        
        // Busca Linear
        clock_t inicio_linear = clock();
        for (int i = 0; i < tamanho; i++) {
            if (dados[i] == valor_busca) break;
        }
        clock_t fim_linear = clock();
        double tempo_linear = (double)(fim_linear - inicio_linear) / CLOCKS_PER_SEC * 1000.0;
        fprintf(fp, "Busca Linear: %.10f ms (valor %d)\n", tempo_linear, valor_busca);
        
        // Busca Binária
        int esq = 0, dir = tamanho - 1, meio, pos = -1;
        clock_t inicio_binaria = clock();
        while (esq <= dir) {
            meio = esq + (dir - esq) / 2;
            if (dados[meio] == valor_busca) {
                pos = meio;
                break;
            } else if (dados[meio] < valor_busca) {
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }
        clock_t fim_binaria = clock();
        double tempo_binaria = (double)(fim_binaria - inicio_binaria) / CLOCKS_PER_SEC * 1000.0;
        fprintf(fp, "Busca Binaria: %.10f ms (valor %d)\n", tempo_binaria, valor_busca);
    } else {
        fprintf(fp, "Nao e possivel comparar buscas, pois o vetor nao esta ordenado.\n");
    }
    
    fclose(fp);
    printf("\nRelatorio de desempenho gerado com sucesso em 'relatorio.txt'!\n");
}


// Menu principal
void menu() {
    int opcao;
    do {
        printf("\n--- MENU TCD ---\n");
        printf("1. Carregar arquivo de dados\n");
        printf("2. Buscar elemento\n");
        printf("3. Ordenar dados\n");
        printf("4. Gerar relatorio (Log)\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                carregar_arquivo();
                break;
            case 2:
                buscar_elemento();
                break;
            case 3:
                ordenar_dados();
                break;
            case 4:
                gerar_relatorio();
                break;
            case 5:
                liberar_memoria();
                printf("Memoria liberada. Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma das 5 opcoes.\n");
        }
        
    } while(opcao != 5);
}


int main() {
    // Inicialização do gerador de números aleatórios se necessário para outros testes
    // srand(time(NULL));
    menu();
    return 0;
}