#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complexo;

Complexo criarComplexo(double real, double imag) {
    Complexo c;
    c.real = real;
    c.imag = imag;
    return c;
}

void destruirComplexo(Complexo *c) {
    c->real = 0;
    c->imag = 0;
}

Complexo somarComplexos(Complexo c1, Complexo c2) {
    Complexo resultado;
    resultado.real = c1.real + c2.real;
    resultado.imag = c1.imag + c2.imag;
    return resultado;
}

Complexo subtrairComplexos(Complexo c1, Complexo c2) {
    Complexo resultado;
    resultado.real = c1.real - c2.real;
    resultado.imag = c1.imag - c2.imag;
    return resultado;
}

Complexo multiplicarComplexos(Complexo c1, Complexo c2) {
    Complexo resultado;
    resultado.real = c1.real * c2.real - c1.imag * c2.imag;
    resultado.imag = c1.real * c2.imag + c1.imag * c2.real;
    return resultado;
}

Complexo dividirComplexos(Complexo c1, Complexo c2) {
    Complexo resultado;
    double denom = c2.real * c2.real + c2.imag * c2.imag;
    resultado.real = (c1.real * c2.real + c1.imag * c2.imag) / denom;
    resultado.imag = (c1.imag * c2.real - c1.real * c2.imag) / denom;
    return resultado;
}

void mostrarComplexo(Complexo c) {
    printf("(%.2lf, %.2lf)\n", c.real, c.imag);
}

int main() {
    Complexo c1 = criarComplexo(2.0, 3.0);
    Complexo c2 = criarComplexo(4.0, 5.0);

    printf("Complexo 1: ");
    mostrarComplexo(c1);

    printf("Complexo 2: ");
    mostrarComplexo(c2);

    Complexo soma = somarComplexos(c1, c2);
    printf("Soma: ");
    mostrarComplexo(soma);

    Complexo sub = subtrairComplexos(c1, c2);
    printf("Subtração: ");
    mostrarComplexo(sub);

    Complexo mul = multiplicarComplexos(c1, c2);
    printf("Multiplicação: ");
    mostrarComplexo(mul);

    Complexo div = dividirComplexos(c1, c2);
    printf("Divisão: ");
    mostrarComplexo(div);

    destruirComplexo(&c1);
    destruirComplexo(&c2);

    return 0;
}
