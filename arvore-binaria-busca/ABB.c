#include <unistd.h>
#include "ABB.h"
#include <stdlib.h>

ArvoreBB* criar_arvore() {
  ArvoreBB* arvore = malloc(sizeof(ArvoreBB));
  arvore->raiz = NULL;
  return arvore;
}

static No* criar_no(int chave) {
  No* no = malloc(sizeof(No));
  no->chave = chave;
  no->direito = NULL;
  no->esquerdo = NULL;
}

static No* buscar_no(No* raiz, int chave) {
  if(raiz->chave == chave) {
    return raiz;
  }
  else if(raiz->chave > chave)
  {
    if(raiz->esquerdo) {
      return buscar_no(raiz->esquerdo, chave);
    }
  }
  else
  {
    if(raiz->direito) {
      return buscar_no(raiz->direito, chave);
    }
  } 
  return NULL;
}

int buscar(ArvoreBB* arvore, int chave) {
  if(!arvore->raiz) {
    return -1;
  }
  No* no = buscar_no(arvore->raiz, chave);
  if(no) {
    return no->chave;
  }
  return -1;
}

static No* inserir_no(No* raiz, int chave) {
  if(!raiz) {
    raiz = criar_no(chave);
  }
  else if(raiz->chave != chave) {
    if(chave < raiz->chave) {
      raiz->esquerdo = inserir_no(raiz->esquerdo, chave);
    }
    else
    {
      raiz->direito = inserir_no(raiz->direito, chave);
    }
  }
  return raiz;
}

void inserir(ArvoreBB* arvore, int chave) {
  arvore->raiz = inserir_no(arvore->raiz, chave);
}

static void destruir_no(No* no) {
  if(no) {
    if(no->esquerdo) {
    destruir_no(no->esquerdo);
    }
    if(no->direito) {
      destruir_no(no->direito);
    }
    free(no);
  }
}

void destruir_arvore(ArvoreBB* arvore) {
  destruir_no(arvore->raiz);
  free(arvore);
}

No* remover_raiz(No* raiz) {
  No* pai;
  No* novaRaiz;
  if(raiz->esquerdo == NULL) {
    novaRaiz = raiz->direito;
    free(raiz);
    return novaRaiz;
  }
  pai = raiz;
  novaRaiz = pai->esquerdo;
  while(novaRaiz->direito) {
    pai = novaRaiz;
    novaRaiz = novaRaiz->direito;
  }
  if(pai != raiz) {
    pai->direito = novaRaiz->esquerdo;
    novaRaiz->esquerdo = raiz->esquerdo;
    novaRaiz->direito = raiz->direito;
    free(raiz);
    return novaRaiz;
  }
}

static No* remover_no(No* raiz, int chave) {
  if(raiz->chave == chave) {
    raiz = remover_raiz(raiz);
  }
  else if(chave < raiz->chave) {
    if(raiz->esquerdo) {
      raiz->esquerdo = remover_no(raiz->esquerdo, chave);
    }
  }
  else
  {
    if(raiz->direito) {
      raiz->direito = remover_no(raiz->direito, chave);
    }
  }
  return raiz;
}

void remover(ArvoreBB* arvore, int chave){
  if(arvore->raiz) {
    remover_no(arvore->raiz, chave);
  }
}

