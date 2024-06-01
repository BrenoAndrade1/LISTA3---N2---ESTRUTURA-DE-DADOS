#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool ehPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void gerarPrimos(int* primos, int max, int* tamanho) {
    for (int i = 2; i <= max; i++) {
        if (ehPrimo(i)) {
            primos[*tamanho] = i;
            (*tamanho)++;
        }
    }
}

void conjecturaGoldbach(int inicio, int fim) {
    int primos[1000];
    int tamanho = 0;
    gerarPrimos(primos, fim, &tamanho);

    for (int n = inicio; n <= fim; n += 2) {
        for (int i = 0; i < tamanho; i++) {
            if (primos[i] > n / 2) break;
            for (int j = i; j < tamanho; j++) {
                if (primos[i] + primos[j] == n) {
                    printf("%d = %d + %d\n", n, primos[i], primos[j]);
                    break;
                }
            }
        }
    }
}

int main() {
    conjecturaGoldbach(700, 1100);
    return 0;
}
