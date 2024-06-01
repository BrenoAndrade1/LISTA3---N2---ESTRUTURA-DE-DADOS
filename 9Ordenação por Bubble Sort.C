#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n, int *num_if, int *num_trocas) {
    *num_if = 0;
    *num_trocas = 0;
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            (*num_if)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*num_trocas)++;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Array original:\n");
    printArray(arr, n);

    int num_if, num_trocas;
    selectionSort(arr, n, &num_if, &num_trocas);

    printf("Array ordenado:\n");
    printArray(arr, n);
    printf("Número de comparações (if): %d\n", num_if);
    printf("Número de trocas: %d\n", num_trocas);

    return 0;
}
