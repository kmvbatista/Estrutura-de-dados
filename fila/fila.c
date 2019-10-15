#include <stdlib.h>
#include "fila.h"


Fila* criar_fila(int tamanho){
    Fila* f = malloc(sizeof(Fila));
    f->dados = malloc(sizeof(int)*tamanho);
    f->M = tamanho;
    f->f = -1;
    f->r = -1;
    f->tamanho = 0;
    return f;
}

void destruir_fila(Fila* f){
    free(f->dados);
    free(f);
}

void inserir(Fila* f, int x){
    if(f->tamanho < f->M) {
        f->tamanho+= 1;
        f->r = (f->r + 1)%f->M;
        f->dados[f->r]= x;
    }
}

int remover(Fila* fi){
    int valor = 0;
    if(fi->tamanho > 0) {
        fi->tamanho-= 1;
        fi->f= (fi->f + 1)%fi->M;
        valor = fi->dados[fi->f];

    }
    return valor;
}

int tamanho(Fila* f){
    return f->tamanho;
}
