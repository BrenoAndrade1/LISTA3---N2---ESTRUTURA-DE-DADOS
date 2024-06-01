#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Empregado {
    char nome[50];
    char data_nascimento[11];
    char RG[12];
    char data_admissao[11];
    float salario;
    struct Empregado* proximo;
} Empregado;

void lerEmpregado(Empregado* e) {
    printf("Nome: ");
    scanf("%s", e->nome);
    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", e->data_nascimento);
    printf("RG: ");
    scanf("%s", e->RG);
    printf("Data de Admissão (dd/mm/aaaa): ");
    scanf("%s", e->data_admissao);
    printf("Salário: ");
    scanf("%f", &e->salario);
}

void escreverEmpregado(Empregado* e) {
    printf("Nome: %s\n", e->nome);
    printf("Data de Nascimento: %s\n", e->data_nascimento);
    printf("RG: %s\n", e->RG);
    printf("Data de Admissão: %s\n", e->data_admissao);
    printf("Salário: %.2f\n", e->salario);
}

Empregado* criarEmpregado() {
    Empregado* novo = (Empregado*)malloc(sizeof(Empregado));
    novo->proximo = NULL;
    return novo;
}

void adicionarEmpregado(Empregado** head) {
    Empregado* novo = criarEmpregado();
    lerEmpregado(novo);
    novo->proximo = *head;
    *head = novo;
}

void listarEmpregados(Empregado* head) {
    Empregado* temp = head;
    while (temp != NULL) {
        escreverEmpregado(temp);
        temp = temp->proximo;
    }
}

void liberarLista(Empregado* head) {
    Empregado* temp;
    while (head != NULL) {
        temp = head;
        head = head->proximo;
        free(temp);
    }
}

int main() {
    Empregado* head = NULL;
    int n;
    printf("Digite o número de empregados: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        adicionarEmpregado(&head);
    }

    printf("\nDados dos empregados:\n");
    listarEmpregados(head);

    liberarLista(head);
    return 0;
}
