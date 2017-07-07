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

	for(i = 0; i < n ; i++){
		 nuevo->lista[i] = crearLista();
		 nuevo->lista[i]->head->info.ciudad = i;
	 }
	return nuevo;
}

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
	G -> arcos++; //aumento en 1 el numero de arcos
	//agrego ambos elementos
	insort(G -> lista[v1], G->lista[v2]->head->info);
	insort(G -> lista[v2], G->lista[v1]->head->info);
}

long int getMark (tGrafo *G,tNodo *nodo)
{
	return G->lista[nodo -> info.ciudad]->mark;
}

void setMark (tGrafo *G, tNodo *nodo, long int marca){
	G -> lista[nodo->info.ciudad] -> mark = marca;
}

void resetMark(tGrafo *G){
	long int i,j;
	i = G -> vertices;
	for(j = 0;j<i;j++) G->lista[j]->mark = 0;
}

long int nVecinos(tGrafo *G, long int ciudad){
	return length(G -> lista[ciudad]);
}

/*
tGrafo *cpyGraph(tGrafo *G){
	long int i;
	tGrafo *nuevo;
	nuevo = malloc(sizeof(tGrafo *));
	nuevo->vertices = G->vertices;
	nuevo->arcos = 0;
	nuevo ->lista = (tLista **)malloc(sizeof(tLista *) *G->vertices);

	for(i = 0; i < n ; i++){
		 nuevo->lista[i] = crearLista();
		 nuevo->lista[i]->head->info.ciudad = i;
	 }
	return nuevo;
}
*/
long int CNodo(tNodo *nodo){
	return nodo->info.ciudad;
}

tNodo *posG(tGrafo *G,long int i){
	return G->lista[i]->head;
}
