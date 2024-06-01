#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sigla[4];
    char cidade[51];
    char pais[31];
    float taxa;
    int capacidade;
} Aeroporto;

void lerAeroporto(Aeroporto* a) {
    printf("Sigla: ");
    scanf("%s", a->sigla);
    printf("Cidade: ");
    scanf("%s", a->cidade);
    printf("País: ");
    scanf("%s", a->pais);
    printf("Taxa: ");
    scanf("%f", &a->taxa);
    printf("Capacidade: ");
    scanf("%d", &a->capacidade);
}

void escreverAeroporto(Aeroporto a) {
    printf("Sigla: %s\n", a.sigla);
    printf("Cidade: %s\n", a.cidade);
    printf("País: %s\n", a.pais);
    printf("Taxa: %.2f\n", a.taxa);
    printf("Capacidade: %d\n", a.capacidade);
}

Aeroporto* redimensionarVetor(Aeroporto* aeroportos, int* capacidade) {
    *capacidade *= 2;
    aeroportos = realloc(aeroportos, *capacidade * sizeof(Aeroporto));
    if (!aeroportos) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return aeroportos;
}

int main() {
    int capacidade = 2, n = 0;
    Aeroporto* aeroportos = (Aeroporto*)malloc(capacidade * sizeof(Aeroporto));

    while (1) {
        char opcao;
        printf("Adicionar um novo aeroporto? (s/n): ");
        scanf(" %c", &opcao);
        if (opcao == 'n') break;
        if (n == capacidade) {
            aeroportos = redimensionarVetor(aeroportos, &capacidade);
        }
        lerAeroporto(&aeroportos[n++]);
    }

    printf("\nDados dos aeroportos:\n");
    for (int i = 0; i < n; i++) {
        escreverAeroporto(aeroportos[i]);
    }

    free(aeroportos);
    return 0;
}
