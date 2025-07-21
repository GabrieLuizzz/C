#include <stdio.h>
#include <stdlib.h>

void triangulolateral(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=1; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int num;

    printf("Digite o valor de n: ");
    scanf("%d", &num);

    triangulolateral(num);

    return 0;
}
