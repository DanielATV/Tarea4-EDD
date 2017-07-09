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
	nuevo = (tGrafo *)malloc(sizeof(tGrafo));
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
* elemento , entrega el primer elemento vecino de la lista.
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
* elemento , entrega  el siguiente elemento vecino de la lista.
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
* void setEdge
******
* Aniade un arco al grafo.
******
* Input:
* tGrafo *G : Puntero al grafo.
* long int v1 : Inicio del arco.
* long int v2 : Final del arco.
******
* Returns:
* void, no retorna parametro.
*****/
void setEdge(tGrafo *G,long int v1,long int v2){
	G -> arcos++;

	insert(G -> lista[v1], G->lista[v2]->head->info);
	insert(G -> lista[v2], G->lista[v1]->head->info);

}
/*****
* long int getMark
******
* Obtiene la marca de la ciudad.
******
* Input:
* tGrafo *G : Puntero al grafo.
* long int ciudad : Ciudad que se desea conocer la  marca.
******
* Returns:
* long int, marca asignada.
*****/
long int getMark (tGrafo *G,long int ciudad){
	return G->lista[ciudad]->mark;
}
/*****
* void setMark 
******
* Aniade una marca a la ciudad.
******
* Input:
* tGrafo *G : Puntero al grafo.
* long int ciudad : Cuidad a la cual aniadir la marca.
* long int marca : Marca que desea.
******
* Returns:
* void, no retorna parametro.
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
* long int nVecinos
******
* Obtiene el numero de vecinos de la ciudad.
******
* Input:
* tGrafo *G : Puntero al grafo.
* long int ciudad : Ciudad que se quiere saber el numero de vecinos.
******
* Returns:
* long int, numero de vecinos.
*****/
long int nVecinos(tGrafo *G, long int ciudad){
	return length(G -> lista[ciudad]);
}
/*****
* tLista *Vecinos
******
* Entrega el puntero a la lista con todos los vecinos de la ciudad.
******
* Input:
* tGrafo *G : Puntero al grafo.
* long int ciudad : Ciudad de interes.
******
* Returns:
* tLista *, puntero a la lista.
*****/
tLista *Vecinos(tGrafo *G,long int ciudad){
	return G->lista[ciudad];
}

