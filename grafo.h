#ifndef __grafo_h__
#define __grafo_h__

#include "lista.h"

//estructura del grafo
typedef struct grafo{
    long int vertices; //numero de vertices
    long int arcos; //numero de arcos
    tLista **lista; //puntero a la lista
} tGrafo;

// inicializa un grafo para n vertices
tGrafo *initGraph (long int);
// libera la memoria utilizada por un grafo
void destroyGraph (tGrafo *);
// retorna el numero de vertices en el grafo
long int nVertex (tGrafo *);
// retorna el numero de arcos en el grafo
long int nEdges (tGrafo *);
// Devuelve el primer vecino de un vertice  dado 
elemento first (tGrafo *, long int);
// devuelve el vecino siguiente  a uno dado
// Retorna NULL si es que no existe
elemento nextg (tGrafo *, long int);
// agrega un nuevo arco al grafo entre vertices v1 y v2
void setEdge (tGrafo *, long int, long int);
// obtiene la marca asignada a un vertice dado
long int getMark (tGrafo *,long int);
// marca un vertice con un valor dado
void setMark (tGrafo *, long int,long int);
//resetea las marcas a 0
void resetMark(tGrafo *);
//imprime los numeros de vecinos de un nodo
long int nVecinos(tGrafo *, long int);
//entrega los vecinos de un nodo a partir de su posicion
tLista *Vecinos(tGrafo *,long int);

#endif
