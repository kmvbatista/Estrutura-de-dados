#include<stdlib.h>
#include<stdio.h>

void insert(int *vetor, int tamanho) {
    int i, j, eleito;

    for(i = 1; i < tamanho; i++) {
        eleito = vetor[i];
        j = i-1;
        while(j >= 0 && eleito < vetor[j]) {
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        vetor[j+1] = eleito;
    }
}

void imprime_insert(int *vetor, int tamanho) {
    int i;
    for(i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
