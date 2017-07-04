#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>


tGrafo *initGraph(long int n){
	long int i;
	tGrafo *nuevo;
	nuevo = malloc(sizeof(tGrafo *));
	nuevo->vertices = n;
	nuevo->arcos = 0;
	nuevo ->lista = (tLista **)malloc(sizeof(tLista *) *n);


	for(i = 0; i < n ; i++) nuevo->lista[i] = crearLista();
	return nuevo;


void destroyGraph (tGrafo *G){
	int i;
	for(i = 0; i < G->vertices; i++) clearL(G->lista[i]);
	free((void *)G->lista);
	G->vertices = 0;
	G->arcos = 0;
}

long int nVertex (tGrafo *G){
	return G -> vertices;
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
	e1.pos = v1;
	e1.mark = G->lista[v1]->head->info.mark;
	e2.pos = v2;
	e2.mark = G->lista[v2]->head->info.mark;
	G -> arcos++; //aumento en 1 el numero de arcos
	//agrego ambos elementos
	append(G -> lista[v1], e2);
	append(G -> lista[v2], e1);
}

long int getMark (tNodo *v)
{
	return *(v -> info.mark);
}

void setMark (tGrafo *G, long int i, long int marca){
	*(G -> lista[i] -> head->info.mark) = marca;
}
