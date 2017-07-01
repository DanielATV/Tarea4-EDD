#ifndef __lista_h__
#define __lista_h__

#include <stdlib.h>
#include "lista.h"
#include "lista.h"

typedef struct grafo{
	tLista *lista;
	long int vertice;
	long int arcos;
} tGrafo;

// inicializa un grafo para n vértices
void initGraph (tGrafo *G, int n); 
// libera la memoria utilizada por un grafo
void destroyGraph (tGrafo *G); 
// retorna el número de vértices en el grafo
long int nVertex (tGrafo *G); 
// retorna el número de arcos en el grafo
long int nEdges (tGrafo *G); 
// Devuelve el primer vecino de un vértice v dado (asume que los
// vecinos de un vértice están ordenados por número de vértice)
tNodo first (tNodo v); 
// devuelve el vecino siguiente (i+1) a uno dado (i).
// Retorna el número total de vértices si es que no existe
tNodo next (tGrafo *G, tNodo v, int i); 
// agrega un nuevo arco al grafo entre vértices v1 y v2 (no se
// pueden agregar nuevos vértices)
void setEdge (tGrafo *G, tNodo v1, tNodo v2, int peso); 
// obtiene la marca asignada a un vértice dado (ciertos algoritmos
// necesitan marcar los vértices)
long int getMark (tGrafo *G, tNodo v); 
// marca un vértice con un valor dado
void setMark (tGrafo *G, tNodo v, int marca); 
