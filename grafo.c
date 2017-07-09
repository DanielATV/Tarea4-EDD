#include "grafo.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/*****
* tGrafo *initGraph
******
* Crea una estructura grafo con n vertices.
******
* Input:
* long int n : Numero de vertices.
******
* Returns:
* tGrafo *, puntero al grafo creado.
*****/
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
/*****
* void destroyGraph
******
* Libera la memoria de cada lista del grafo y del grafo.
******
* Input:
* tGrafo *G : Puntero al grafo que se desea liberar la memoria.
******
* Returns:
* void, no retorna parametro.
*****/
void destroyGraph (tGrafo *G){
	int i;
	for(i = 0; i < G->vertices; i++) clearL(G->lista[i]);
	free((void *)G->lista);
	free((void*) G);
}
/*****
* long int nVertex
******
* Entrega el numero de vertices del grafo.
******
* Input:
* tGrafo *G : Puntero al grafo.
******
* Returns:
* long int, numero de vertices.
*****/
long int nVertex (tGrafo *G){
	return G -> vertices;
}
/*****
* long int nEdges
******
* Entrega el numero de arcos del grafo.
******
* Input:
* tGrafo *G : Puntero al grafo.
******
* Returns:
* long int, numero de arcos.
*****/
long int nEdges(tGrafo *G){
	return G->arcos;
}

/*****
* elemento first
******
* Entrega el primer vecino del grafo en el vertice i.
******
* Input:
* tGrafo *G : Puntero al grafo.
* long int i: Vertice al que se desea obtener el primer vecino.
******
* Returns:
* elemento , entrega el primer tNodo vecino de la lista i.
*****/
elemento first (tGrafo *G, long int i){
	moveToStart(G->lista[i]);
	return getValue(G -> lista[i]);
} 
/*****
* elemento nextg
******
* Entrega el siguiente vecino del grafo en el vertice i.
******
* Input:
* tGrafo *G : Puntero al grafo.
* long int i: Vertice al que se desea obtener el primer vecino.
******
* Returns:
* elemento , entrega  el siguiente tNodo vecino de la lista i.
*****/
elemento nextg (tGrafo *G,long int i){
	elemento aux;
	if(next(G->lista[i]) == G->lista[i]->listSize){
		aux.ciudad = G->lista[i]->listSize;
		return aux;
	}
	else return getValue(G->lista[i]);
} 
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
void setEdge(tGrafo *G,long int v1,long int v2){
	G -> arcos++; //aumento en 1 el numero de arcos
	//agrego ambos elementos
	insert(G -> lista[v1], G->lista[v2]->head->info);
	insert(G -> lista[v2], G->lista[v1]->head->info);

}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
long int getMark (tGrafo *G,long int ciudad){
	return G->lista[ciudad]->mark;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
void setMark (tGrafo *G, long int ciudad, long int marca){
	G -> lista[ciudad] -> mark = marca;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
void resetMark(tGrafo *G){
	long int j;
	for(j = 0;j< G -> vertices ;j++) G->lista[j]->mark = 0;
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
long int nVecinos(tGrafo *G, long int ciudad){
	return length(G -> lista[ciudad]);
}
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
tLista *Vecinos(tGrafo *G,long int ciudad){
	return G->lista[ciudad];
}

