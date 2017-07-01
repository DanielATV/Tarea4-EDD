

#include "grafo.h"
#include "list.h"
#include "lista.c"

void destroyGraph (tGrafo *G)
{
	clearL(G->lista);
	G->vertice = 0;
	G->arcos = 0;
}


tNodo first (tGrafo *G, tNodo v)
{
	return v->sig;
}

int getMark (tGrafo *G, tNodo v)
{
	return v->info->marca;
}



