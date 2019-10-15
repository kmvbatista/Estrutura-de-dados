#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct No{
	// exemplo usando chave inteira
	int chave;

} No;

typedef struct Lista{
  No* elementos; // elemento que está na lista
  int tamanho; // tamanho atual da lista
  int limite; // limite da lista
} Lista;

// cria uma lista com tamanho definido
Lista* criar_lista(int tamanho);
// destroi a lista
void destruir_lista(Lista* l);
// retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista* l);
// retorna quantidade maxima de elementos
int limite(Lista* l);
// busca um dado pela chave x. retorna NULL em caso de falha
No* buscar(Lista* l, int x);
// insere um dado pela (chave x). retorna NULL em caso de falha
No* inserir(Lista* l, int x);
// remove dado da lista
void remover(Lista* l, int x);
// retorna o primeiro da lista
No* primeiro(Lista* l);
// retorna o ultimo da lista
No* ultimo(Lista* l);
// retorna um elemento pela posicao
No* buscar_por_indice(Lista* l, int i);

#endif // LISTA_H_INCLUDED
