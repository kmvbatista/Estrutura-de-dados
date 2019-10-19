#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{

    No* A = criar_arvore('A');
    No* B = criar_arvore('B');
    No* C = criar_arvore('C');
    No* D = criar_arvore('D');
    No* E = criar_arvore('E');
    No* F = criar_arvore('F');
    No* G = criar_arvore('G');
    No* H = criar_arvore('H');
    No* I = criar_arvore('I');
/*
.........................A....................
......................./...\..................
....................../.....\.................
...................../.......\................
..................../.........\...............
.................../...........\..............
................../.............\.............
................./...............\............
.................B................C...........
.............../..\............../..\.........
............../....\............/....\........
............./.....NULL......../......\.......
............/................./........\......
...........D..................E.........F.....
........../.\................/.\......./.\....
........./...\............../...\...../...\...
...... ./....NULL........../.....\..NULL.NULL.
......./................../.......\...........
......G..................H.........I..........
...../.\................/.\......./.\.........
..../...\............../...\...../...\........
..NULL.NULL..........NULL.NULL.NULL.NULL......
..............................................
..............................................
*/

    inserir(A, B, C);
    inserir(B, D, NULL);
    inserir(D, G, NULL);

    inserir(C, E, F);
    inserir(E, H, I);

    imprimir_preordem(A);
    printf("\n");
    imprimir_simetrica(A);
    printf("\n");
    imprimir_posordem(A);
    imprimir_largura(A);
    return 0;
}
