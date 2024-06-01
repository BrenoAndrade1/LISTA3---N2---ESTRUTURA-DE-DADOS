#include <stdio.h>

double calcularEx(double x, int precisao) {
    double soma = 1.0; // e^0 = 1
    double termo = 1.0;

    for (int i = 1; i <= precisao; i++) {
        termo *= x / i;
        soma += termo;
    }

    return soma;
}

int main() {
    double x;
    int precisao;

    printf("Digite o valor de x: ");
    scanf("%lf", &x);
    printf("Digite a precisão desejada (número de termos): ");
    scanf("%d", &precisao);

    double resultado = calcularEx(x, precisao);
    printf("e^%.2lf ≈ %.6lf\n", x, resultado);

    return 0;
}
