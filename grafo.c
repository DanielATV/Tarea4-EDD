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
	insert(G -> lista[v1], G->lista[v2]->head->info);
	insert(G -> lista[v2], G->lista[v1]->head->info);
}

long int getMark (tGrafo *G,long int posicion)
{
	return *(G->lista[posicion]->head-> info.mark);
}

void setMark (tGrafo *G, long int i, long int marca){
	*(G -> lista[i] -> head->info.mark) = marca;
}

void resetMark(tGrafo *G){
	long int i,j;
	i = G -> vertices;
	for(j = 0;j<i;j++) *(G->lista[j]->head->info.mark) = 0;
}

long int nVecinos(tGrafo *G, long int ciudad){
	return length(G -> lista[ciudad]);
}

tGrafo *subGraph(tGrafo *G, long int * amigos, long int num_amigos){
	tGrafo *B;
	elemento aux;
	long int i;

	aux.mark = (long int *)malloc(sizeof(long int));
	B = initGraph(G->vertices);

	for (i = 0; i < num_amigos;i++){
		for(moveToStart(G->lista[amigos[i]]); G->lista[i]->pos < G->lista[i]->listSize; next(G->lista[amigos[i]])){
			aux.ciudad = getValue(G->lista[amigos[i]]).ciudad;
			insert(B->lista[amigos[i]],aux);
		}
	}
	free((void *)aux.mark);
	return B;
}
