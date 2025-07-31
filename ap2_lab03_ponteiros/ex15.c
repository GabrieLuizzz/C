#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2) {
    if (A == 0) {
        return 0;
    }

    float delta = B * B - 4 * A * C;

    if (delta < 0) {
        return 0;
    } else if (delta == 0) {
        *X1 = -B / (2 * A);
        *X2 = *X1;
        return 1;
    } else {
        *X1 = (-B + sqrt(delta)) / (2 * A);
        *X2 = (-B - sqrt(delta)) / (2 * A);
        return 2;
    }
}
int main() {
    float a = 1.0, b = -3.0, c = 2.0;
    float raiz1, raiz2;
    int num_raizes;

    num_raizes = raizes(a, b, c, &raiz1, &raiz2);

    if (num_raizes == 2) {
        printf("A equacao tem duas raizes reais: %.2f e %.2f\n", raiz1, raiz2);
    } else if (num_raizes == 1) {
        printf("A equacao tem uma raiz real: %.2f\n", raiz1);
    } else {
        printf("A equacao nao tem raizes reais.\n");
    }

    return 0;
}