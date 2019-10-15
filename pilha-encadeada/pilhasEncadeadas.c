#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


void main() {
    Pilha* pilha= criarPilha();
    push(pilha, 3);
    push(pilha, 4);
    push(pilha, 5);
    imprimir(pilha);
    destruir(pilha);
}
	
