#include "grafo.h"
#include "lista.h"

void initGraph(tGrado *G, int n){
	G->lista = (tLista *)malloc(sizeof(tLista)*n);
	G->vertices = 0;
	G->arcos = 0;
}

void destroyGraph (tGrafo *G)
{
	clearL(G->lista);
	G->vertice = 0;
	G->arcos = 0;
}

long int nVertex (tGrafo *G){
	int n;
	n = G -> vertices;
	return n;
}

long int nEdges(tGrafo *G){
	return G->arcos;
}

tNodo *nextg (tNodo *v)
{
	return v->sig;
}

tNodo *first (tGrafo *G, long int i){
	tNodo *np;
	np = G -> lista[i] -> head -> sig;
	return np;
}

void setEdge(tGrafo *G,long int v1,long int v2){
	elemento e1,e2;
	// modifico ambos elementos
	e1 -> pos = v1;
	e2 -> pos = v2;
	G -> arcos++; //aumento en 1 el numero de arcos
	//agrego ambos elementos
	append(G -> lista[v1], e2);
	append(G -> lista[v2], e1);
}

long int getMark (tNodo *v)
{
	return v->info->marca;
}

void setMark (tGrafo *G, long int i, long int marca){
	G -> lista[i] -> head -> info -> mark = marca;
}


