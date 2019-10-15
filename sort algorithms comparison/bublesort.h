#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void bolha(int *vetor, int tamanho) {
    int i, j, temp;

    for(i = 0; i < tamanho -1; i++) {
        for(j = 0;  j < tamanho - i - 1; j++) {
            if(vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void imprime_buble(int *vetor, int tamanho) {
    int i;
    for(i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}