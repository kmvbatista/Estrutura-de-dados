#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct No{
    int chave;
    struct No* esquerdo;
    struct No* direito;
} No;

typedef struct ArvoreBB{
    No* raiz;
} ArvoreBB;

ArvoreBB* criar_arvore();
void destruir_arvore(ArvoreBB* arvore);
int buscar(ArvoreBB* arvore, int chave);
void inserir(ArvoreBB* arvore, int chave);
void remover(ArvoreBB* arvore, int chave);

#endif // ABB_H_INCLUDED
