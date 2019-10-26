#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int main()
{
    printf("Criando arvore\n");
    ArvoreBB* arvore = criar_arvore();

    inserir(arvore, 31);
    inserir(arvore, 25);
    inserir(arvore, 44);
    inserir(arvore, 5);
    inserir(arvore, 28);
    inserir(arvore, 39);
    inserir(arvore, 57);
    inserir(arvore, 120);
    inserir(arvore, 41);

    printf("->%d\n", buscar(arvore,39));
    printf("->%d\n", buscar(arvore,10));
    printf("->%d\n", buscar(arvore,4));
    printf("->%d\n", buscar(arvore,5));
    printf("->%d\n", buscar(arvore,28));

    printf("Removendo algumas chaves\n");

    remover(arvore, 39);
    remover(arvore, 10);
    remover(arvore, 4);
    remover(arvore, 5);
    remover(arvore, 28);

    printf("->%d\n", buscar(arvore,39));
    printf("->%d\n", buscar(arvore,10));
    printf("->%d\n", buscar(arvore,4));
    printf("->%d\n", buscar(arvore,5));
    printf("->%d\n", buscar(arvore,28));

    destruir_arvore(arvore);
    return 0;
}
