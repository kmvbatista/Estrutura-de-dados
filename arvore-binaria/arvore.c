#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>


No* criar_arvore(char chave){
    No* no = malloc(sizeof(No));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

No* inserir(No* arvore, No* esquerdo, No* direito){
    arvore->esquerda = esquerdo;
    arvore->direita = direito;

    return arvore;
}

void imprimir_preordem(No* no){
  printf("%c", no->chave);
  if(no->esquerda != NULL) {
    imprimir_preordem(no->esquerda);
  }
  if(no->direita != NULL) {
    imprimir_preordem(no->direita);
  }
}

void imprimir_simetrica(No* no){
  if(no->esquerda != NULL) {
    imprimir_posordem(no->esquerda);
  }
  printf("%c", no->chave);
  if(no->direita != NULL) {
    imprimir_posordem(no->direita);
  }
}
void imprimir_posordem(No* no){
  if(no->esquerda != NULL) {
    imprimir_posordem(no->esquerda);
  }
  if(no->direita != NULL) {
    imprimir_posordem(no->direita);
  }
  printf("%c", no->chave);
}

void imprimir_largura(No* no) {
  No* Fila[100];
  int inicio = 0;
  int fim = 0;
  Fila[fim++] = no;
  while (inicio <= fim)
  {
    No* aux;
    aux = Fila[inicio++];
    printf("%c", aux->chave);
    if(aux->esquerda) {
      Fila[fim++] = aux->esquerda;
    }
    if(aux->direita) {
      Fila[fim++] = aux->direita;
    }
  }
}
