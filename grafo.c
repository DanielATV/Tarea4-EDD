#include "grafo.h"
#include "lista.h"


void destroyGraph (tGrafo *G)
{
	clearL(G->lista);
	G->vertice = 0;
	G->arcos = 0;
}


tNodo *next (tNodo *v)
{
	return v->sig;
}

long int getMark (tNodo *v)
{
	return v->info->marca;
}

long int nVertex (tGrafo *G){
	int n;
	n = G -> vertices;
	return n;
}

tVertice *first (tGrafo *G, long int i){
	tNodo *np;
	np = G -> lista[i] -> head -> sig;
	return np;
}

void setMark (tGrafo *G, long int i, long int marca){
	G -> lista[i] -> head -> mark = marca;
}


