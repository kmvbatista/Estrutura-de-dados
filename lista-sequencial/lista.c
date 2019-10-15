#include <stdlib.h>
#include "lista.h"


Lista* criar_lista(int tamanho){
	Lista* l = malloc(sizeof(Lista));
	l->elementos = malloc(sizeof(No)*tamanho);
	l->tamanho = 0;
	l->limite = tamanho;
	return l;
}

void destruir_lista(Lista* l){
	free(l->elementos);
	free(l);
}

int tamanho(Lista* l){
	return l->tamanho;
}

int limite(Lista* l){
	return l->limite;
}


No* buscar(Lista* l, int x) {
    int i = 0;
    No* buscado = NULL;
    while(i<tamanho(l)) {
        if(l->elementos[i].chave == x ){
            buscado = &l->elementos[i];
            return buscado;
        }
        else {
            i++;
        }
    }
    return NULL;
}

int buscarIndice(Lista* l, int x) {
    int i = 0;
    No* buscado = NULL;
    while(i<tamanho(l)) {
        if(l->elementos[i].chave == x ){
            buscado = &l->elementos[i];
            return i;
        }
        else {
            i++;
        }
    }
    return -1;

}


No* inserir(Lista* l,int x ) {
    if(buscar(l, x)==NULL) {
        int pos = tamanho(l);
        l->elementos[pos].chave = x;
        l->tamanho++;
    return &l->elementos[pos];
    }

}

void remover(Lista* l, int x){
    int i = buscarIndice(l, x);
    if(i>=0) {
        for(i; i<tamanho(l)-2; i++) {
            l[i] = l[i+1];
        }
        l->tamanho= l->tamanho-1;
    }
}
// retorna o primeiro da lista
No* primeiro(Lista* l) {
    return &l->elementos[0];
}
// retorna o ultimo da lista
No* ultimo(Lista* l){
    return &l->elementos[tamanho(l)-1];

}
// retorna um elemento pela posicao
No* buscar_por_indice(Lista* l, int i) {
    return &l->elementos[i];
}
