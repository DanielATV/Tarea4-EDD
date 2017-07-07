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

tGrafo *cpyGraph(tGrafo *G){
    tGrafo *B;
    long int i;
    elemento aux;

    B = malloc(sizeof(tGrafo *));
    B->vertices = G->vertices;
    B->arcos = G->arcos;
    B ->lista = (tLista **)malloc(sizeof(tLista *) * G->vertices);

		for(i = 0; i < G->vertices ; i++){
				B->lista[i] = crearLista();
		}
    for(i = 0; i < G->vertices ; i++){
				
				for(moveToStart(G->lista[i]); G->lista[i]->pos < G->lista[i]->listSize; next(G->lista[i])){
						aux.mark = B->lista[getValue(G->lista[i]).ciudad]->head->info.mark;
						aux.ciudad = getValue(G->lista[i]).ciudad;
						insert(B->lista[i],aux);
				}
    }
    return B;
}
