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
* tGrafo *, Puntero al grafo creado.
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
* void, No retorna parametro.
*****/
void destroyGraph (tGrafo *G){
	int i;
	for(i = 0; i < G->vertices; i++) clearL(G->lista[i]);
	free((void *)G->lista);
	free((void*) G);
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
long int nVertex (tGrafo *G){
	return G -> vertices;
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
long int nEdges(tGrafo *G){
	return G->arcos;
}
//a partir de un nodo entrega el siguiente
//entrega NULL si ya no hay mas
elemento nextg (tGrafo *G,long int i){
	elemento aux;
	if(next(G->lista[i]) == G->lista[i]->listSize){
		aux.ciudad = G->lista[i]->listSize;
		return aux;
	}
	else return getValue(G->lista[i]);
} //quiero cambiar para que entregue elemento y aplique el next() de lista
//entrega un nodo como primer vecino de una ciudad,
//este primer vecino es arbitrario si se guarda con insert()
elemento first (tGrafo *G, long int i){
	moveToStart(G->lista[i]);
	return getValue(G -> lista[i]);
} //quiero que entregue un elemento y haga moveToStart() de la lista
//agrega un arco a 2 ciudades dadas, se puede cambiar por insort()
//para que sea en orden
void setEdge(tGrafo *G,long int v1,long int v2){
	G -> arcos++; //aumento en 1 el numero de arcos
	//agrego ambos elementos
	insert(G -> lista[v1], G->lista[v2]->head->info);
	insert(G -> lista[v2], G->lista[v1]->head->info);

}
//obtengo la marca a partir de un nodo
long int getMark (tGrafo *G,long int ciudad){
	return G->lista[ciudad]->mark;
}
//agrega a un nodo una marca, lo guarda como variable de la lista
void setMark (tGrafo *G, long int ciudad, long int marca){
	G -> lista[ciudad] -> mark = marca;
}
//resetea todas las marcas de todos los nodos
void resetMark(tGrafo *G){
	long int j;
	for(j = 0;j< G -> vertices ;j++) G->lista[j]->mark = 0;
}
//entrega el numero de vecinos que tiene un nodo
long int nVecinos(tGrafo *G, long int ciudad){
	return length(G -> lista[ciudad]);
}
//entrega una lista con los vecinos de la posicion de una lista
tLista *Vecinos(tGrafo *G,long int ciudad){
	return G->lista[ciudad];
}

int isEdge (tGrafo *G, long int m, long int n){
	return 0;
}

