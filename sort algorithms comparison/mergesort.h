#include <stdio.h> 
#include <stdlib.h> 

void mergesort(int vetor[], int aux[], int inicio, int fim) { 
    if(inicio< fim){ 
        //divisao 
        int meio = (inicio+fim)/2; 
        mergesort(vetor, aux, inicio, meio); 
        mergesort(vetor, aux, meio+1, fim); 
        
        //conquista 
        int esquerda = inicio; 
        int direita = meio+1; 
        int posicao = inicio; 

        while(esquerda <= meio && direita <= fim) { 
            if(vetor[esquerda] < vetor[direita]) { 
                aux[posicao++] = vetor[esquerda++]; 
            } 
            else{ 
                aux[posicao++] = vetor[direita++];  
            } 
        } 

        while(esquerda <= meio) { 
            aux[posicao++] = vetor[esquerda++]; 
        } 

        while(direita <= fim) { 
            aux[posicao++] = vetor[direita++]; 
        } 

        while(inicio <= fim) { 
            vetor[inicio] = aux[inicio]; 
            inicio++; 
        } 
    } 
}

