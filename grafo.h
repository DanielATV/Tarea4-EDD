#ifndef __grafo_h__
#define __grafo_h__

#include "lista.h"

//estructura del grafo
typedef struct grafo{
    long int vertices; //numero de vertices
    long int arcos; //numero de arcos
    tLista **lista; //puntero a la lista
} tGrafo;

// inicializa un grafo para n vertices--S
tGrafo *initGraph (long int);
// libera la memoria utilizada por un grafo--F
void destroyGraph (tGrafo *);
// retorna el numero de vertices en el grafo--D
long int nVertex (tGrafo *);
// retorna el numero de arcos en el grafo--S
long int nEdges (tGrafo *);
// Devuelve el primer vecino de un vertice v dado (asume que los
// vecinos de un vertice estan ordenados por número de vertice)--D
tNodo *nextg (tNodo *);
// devuelve el vecino siguiente (i+1) a uno dado (i).
// Retorna el numero total de vertices si es que no existe--D
tNodo *first (tGrafo *, long int);
// agrega un nuevo arco al grafo entre vertices v1 y v2 (no se
// pueden agregar nuevos vertices)--S
void setEdge (tGrafo *, long int, long int);
// obtiene la marca asignada a un vertice dado (ciertos algoritmos
// necesitan marcar los vertices)---F
long int getMark (tGrafo *,tNodo *);
// marca un vertice con un valor dado---D
void setMark (tGrafo *, tNodo *,long int);
//resetea las marcas a 0
void resetMark(tGrafo *);
//imprime los numeros de vecinos de un nodo
long int nVecinos(tGrafo *, long int);
//crea una copia del grafo
//tGrafo *cpyGraph(tGrafo *);
//a partir de un nodo entrega la posicion de este
long int CNodo(tNodo *);
//a partir de una posicion entrega el nodo con la informacion
tNodo *posG(tGrafo *,long int);
#endif
