
typedef struct No {
	int dado;
	struct No* prox;
}No;
	

typedef struct Pilha
{
	No* topo;
}Pilha;

void push(Pilha* pilha, int x) {
	No* pt = malloc(sizeof (No));
	pt->dado = x;
	pt->prox = pilha->topo;
	pilha->topo = pt;
}

int pop(Pilha* pilha) {
	int valor = 0;
	No* pt;
	pt = pilha->topo;
	pilha->topo = pt->prox;
	valor = pt->dado;
	free(pt);
	return valor;
}

void imprimir(Pilha* pilha) {
	while (pilha->topo != NULL)
	{
		printf("%d\n",pilha->topo->dado);
		pilha->topo = pilha->topo->prox;
	}
}

Pilha* criarPilha() {
	Pilha* p = malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

