#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void main() {
    Fila* fila = criarFila();
    adicionar(fila, 5);
    adicionar(fila, 3);
    adicionar(fila, 1);
    imprimir(fila);
    destruir(fila);
}