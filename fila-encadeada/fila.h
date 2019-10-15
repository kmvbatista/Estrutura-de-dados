typedef struct No {
	int dado;
	struct No* prox;
}No;

typedef struct Fila
{
    No* inicio;
    No* fim;
}Fila;

void adicionar(Fila* fila, int x) {
    No* pt = malloc(sizeof(No));
    pt->dado = x;
    pt->prox = NULL;
    if(fila->fim != NULL) {
        fila->fim->prox = pt;
    }
    else
    {
        fila->inicio = pt;
    }
    fila->fim = pt;    
}

int remover(Fila* fila) {
    if(fila->inicio == NULL) {
        int valor = 0;
        No* pt = fila->inicio;
        fila->inicio = fila->inicio->prox;
        if(fila->inicio != NULL) {
            fila->inicio = NULL;
        }
        valor = pt->dado;
        free(pt);
        return valor;
    }
}

Fila* criarFila() {
    Fila* fila = malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void imprimir(Fila* fila) {
    No* pt = fila->inicio;
	while (pt != NULL)
	{
		printf("%d\n",pt->dado);
		pt = pt->prox;
	}
}

void destruir(Fila* fila) {
	No* pt = fila->inicio;
	while (pt != NULL)
	{
		No* prox = pt->prox;
		free(pt);
		pt = prox;
	}
    imprimir(fila);
    free(fila); 
}
 