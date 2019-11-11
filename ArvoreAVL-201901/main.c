#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ABB.h"

 unsigned long long rdtscl(void) {
        unsigned int lo, hi;
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
    }

int main()
{
    printf("Criando arvore AVL\n");
    ArvoreAVL* arvore = criar_arvore();

    int i;
    int qtdNumeros;
    printf("Quantos números, SIR?");
    scanf("%d", &qtdNumeros);
    for(i=0; i< qtdNumeros; i++){
        printf("número %d", i);
        unsigned long long inicio = rdtscl();
        inserir(arvore, i);
        unsigned long long final = rdtscl();
        printf("  |tempo de inserção é: %lld", final-inicio);
        inicio = rdtscl();
        buscar(arvore, i);
        final = rdtscl();
        printf(" |tempo de busca é: %lld\n", final-inicio);
    }
    
    
    //printf("Raiz1: %d\n", arvore->raiz->chave);
    //printf("Altura1: %d\n", altura(arvore));

    destruir_arvore(arvore);

    return 0;
}

   
