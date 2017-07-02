#ifndef __grafo_h__
#define __grafo_h__

#include "lista.h"
#include <stdio.h>

//estructura del grafo
typedef struct grafo{
    long int vertices; //numero de vertices
    long int arcos; //numero de arcos
    tLista *lista[]; //puntero a la lista
} tGrafo;

// inicializa un grafo para n vertices--S
void initGraph (tGrafo *G, long int n); 
// libera la memoria utilizada por un grafo--F
void destroyGraph (tGrafo *G); 
// retorna el numero de vertices en el grafo--D
long int nVertex (tGrafo *G); 
// retorna el numero de arcos en el grafo--S
long int nEdges (tGrafo *G); 
// Devuelve el primer vecino de un vertice v dado (asume que los
// vecinos de un vertice estan ordenados por número de vertice)--D
tNodo *nextg (tNodo *v); 
// devuelve el vecino siguiente (i+1) a uno dado (i).
// Retorna el numero total de vertices si es que no existe--D
tNodo *first (tGrafo *G, long int i); 
// agrega un nuevo arco al grafo entre vertices v1 y v2 (no se
// pueden agregar nuevos vertices)--S
void setEdge (tGrafo *G, long int v1, long int v2); 
// obtiene la marca asignada a un vertice dado (ciertos algoritmos
// necesitan marcar los vertices)---F
long int getMark ( tNodo *v); 
// marca un vertice con un valor dado---D
void setMark (tGrafo *G, long int i,long int marca); 
#endif
