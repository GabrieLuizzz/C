#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

void cal_esfera(float R, float *area, float *vol) {
    *area = 4 * PI * pow(R, 2);
    *vol = (4.0 / 3.0) * PI * pow(R, 3);
}

int main() {
    float raio;
    float area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    cal_esfera(raio, &area, &volume);

    printf("Area da superficie: %.2f\n", area);
    printf("Volume da esfera: %.2f\n", volume);

    return 0;
}
