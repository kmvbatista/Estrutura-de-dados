#include <stdlib.h>
#include "lista.h"
#include <stdio.h>


No* busca_enc(Lista* l, int x, No** ant) {
    No* pont = NULL;
    *ant = l->ptlista;
    No* ptr = l->ptlista->prox;
    while(ptr) {
        if(ptr->chave < x) {
            *ant = ptr;
            ptr = ptr->prox;
        }
        else if(ptr->chave==x) {
            pont = ptr;
            ptr = NULL;
        }
        else {
            ptr=NULL;
        }
    }
    return pont;
}

No* inserir(Lista* l, int x, No* novoValor) {
    No* ant = NULL;
    No* pont = NULL;
    if(!busca_enc(l, x, &ant)) {
        No* pt = malloc(sizeof(No));
        pt->chave=x;
        pt->prox= ant->prox;
        ant->prox= pt;
        return novoValor;
    }
    return NULL;
}

void remover(Lista* l, int x) {
    No* ant = NULL;
    No* pt = busca_enc(l, x, &ant);
    if(pt) {
        ant->prox = pt->prox;
        free(pt);
    }
}


void destruir_lista(Lista* l) {
    No* pont = l->ptlista;
    No* aux = NULL;
    while (pont)
    {
        aux = pont->prox;
        free(pont);
        pont= aux;
    }
}

void main() {

}

void imprimir(Lista* l) {
    No* pont = l->ptlista;
    while (pont)
    {
        printf("%d\n", pont->chave);
    }
}

Lista* criar_lista(int tamanho){
    Lista* l = malloc(tamanho * sizeof(Lista));
    return l;
}