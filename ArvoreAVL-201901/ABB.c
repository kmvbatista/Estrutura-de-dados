#include <stdlib.h>
#include <stdio.h>
#include "ABB.h"

#define BALANCEAR 1

ArvoreAVL* criar_arvore(){
    ArvoreAVL* arvore = malloc(sizeof(ArvoreAVL));
    arvore->raiz = NULL;
    return arvore;
}

static No* criar_no(int chave){
    No* no = malloc(sizeof(No));
    no->chave = chave;
    no->direito = NULL;
    no->esquerdo = NULL;
    no->peso = 1;
    return no;
}

static void destruir_no(No* no){

    if(no->esquerdo){
        destruir_no(no->esquerdo);
    }
    if(no->direito){
        destruir_no(no->direito);
    }
    free(no);
}

void destruir_arvore(ArvoreAVL* arvore){

    if(!arvore->raiz){
        destruir_no(arvore->raiz);
    }
}

static int max(int a, int b){
    return a > b ? a : b;
}

static int peso(No* no){
    if(!no){
        return 0;
    }
    return no->peso;
}

static int fator_bal(No* no){
    if (!no){
        return 0;
    }
    return peso(no->direito) - peso(no->esquerdo);
}

static No* rotacao_direita(No* amarelo){
    No* verde = amarelo->esquerdo;
    No* b = verde->direito;

    verde->direito = amarelo;
    amarelo->esquerdo = b;

    verde->peso = max(peso(verde->esquerdo), peso(verde->direito))+1;
    amarelo->peso = max(peso(amarelo->esquerdo), peso(amarelo->direito))+1;

    return verde;
}

static No* rotacao_esquerda(No* verde){
    No* amarelo = verde->direito;
    No* b = amarelo->esquerdo;

    amarelo->esquerdo = verde;
    verde->direito = b;

    amarelo->peso = max(peso(amarelo->esquerdo), peso(amarelo->direito))+1;
    verde->peso = max(peso(verde->esquerdo), peso(verde->direito))+1;

    return amarelo;
}

static No* balancear(No* no){

    if(!BALANCEAR){
        return no;
    }

    no->peso = 1 + max(peso(no->esquerdo),
                           peso(no->direito));

    int fator_pai = fator_bal(no);
    int fator_esq = fator_bal(no->esquerdo);
    int fator_dir = fator_bal(no->direito);


    if(fator_pai <= -2 && fator_esq == -1){
        no = rotacao_direita(no);
    } else if(fator_pai <= -2 && fator_esq == 1){
        no->esquerdo = rotacao_esquerda(no->esquerdo);
        no = rotacao_direita(no);
    } else if(fator_pai >= 2 && fator_dir == 1){
        no = rotacao_esquerda(no);
    } else if(fator_pai >= 2 && fator_dir == -1){
        no->direito = rotacao_direita(no->direito);
        no = rotacao_esquerda(no);
    }
    return no;

}

static No* buscar_no(No* no, int chave){
    if(no->chave == chave){
        return no;
    } else if(chave < no->chave){
        if(!no->esquerdo){
            return no;
        } else {
            return buscar_no(no->esquerdo, chave);
        }
    } else {
        if(!no->direito){
            return no;
        } else {
            return buscar_no(no->direito, chave);
        }
    }
}

int buscar(ArvoreAVL* arvore, int chave){
    int valor = -1;

    if(arvore->raiz){
        No* buscado = buscar_no(arvore->raiz, chave);

        if(buscado->chave == chave){
            valor = chave;
        }
    }
    return valor;
}

static No* inserir_no(No* n, int chave){

    if (!n){
        return(criar_no(chave));
    }
    if (chave < n->chave){
        n->esquerdo  = inserir_no(n->esquerdo, chave);
    }else if (chave > n->chave){
        n->direito = inserir_no(n->direito, chave);
    }else{
        return n;
    }

    n = balancear(n);

    return n;
}

void inserir(ArvoreAVL* arvore, int chave){

    arvore->raiz = inserir_no(arvore->raiz, chave);

}

static No* remover_raiz(No* raiz){
    No* pai;
    No* nova_raiz;

    if(!raiz->esquerdo){
        nova_raiz = raiz->direito;
        free(raiz);
        return nova_raiz;
    }
    pai = raiz;
    nova_raiz = raiz->esquerdo;

    while(nova_raiz->direito){
        pai = nova_raiz;
        nova_raiz = nova_raiz->direito;
    }

    if(pai != raiz){
        pai->direito = nova_raiz->esquerdo;
        nova_raiz->esquerdo = raiz->esquerdo;
    }

    nova_raiz->direito = raiz->direito;
    free(raiz);
    return nova_raiz;
}


static No* remover_no(No* raiz, int chave){

    if(raiz->chave == chave){
        raiz = remover_raiz(raiz);
    } else if(chave < raiz->chave){
        if(raiz->esquerdo){
            raiz->esquerdo = remover_no(raiz->esquerdo, chave);
        }
    } else {
        if(raiz->direito){
            raiz->direito = remover_no(raiz->direito, chave);
        }
    }

    if(raiz){
        raiz = balancear(raiz);
    }

    return raiz;
}

void remover(ArvoreAVL* arvore, int chave){

    if(arvore->raiz){
        arvore->raiz = remover_no(arvore->raiz, chave);
    }
}

static int altura_no(No* no){
    int altura = 0;
    if(no){
        altura = max(altura_no(no->esquerdo), altura_no(no->direito)) + 1;
    }
    return altura;
}

int altura(ArvoreAVL* arvore){
    int altura = 0;
    if(arvore->raiz){
        altura = altura_no(arvore->raiz);
    }
    return altura;
}



