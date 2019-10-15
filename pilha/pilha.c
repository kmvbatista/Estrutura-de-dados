#include <stdlib.h>
#include "pilha.h"


Pilha* criar_pilha(int tamanho){
    Pilha* p = malloc(sizeof(Pilha));
    p->dados = malloc(sizeof(int)*tamanho);
    p->M = tamanho;
    p->topo = -1;
    return p;
}

void push(Pilha* p, int x){
    if(p->topo != p->M) {
        p->topo = p->topo+1;
        p->dados[p->topo] = x;
    }
}

int pop(Pilha* p){
    int valor = 0;
    if(p->topo != -1) {
        valor = p->dados[p->topo];
        p->topo = p->topo -1;
    }
    return valor;
}

int tamanho(Pilha* p){
    return p->M;
}
