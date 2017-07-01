
#ifndef __fab_h__
#define __fab_h__

#include <stdio.h>

typedef struct elemento{
 long int num;
 long int marca;
} elemento;

typedef struct nodo {
 elemento info; // el elemento en sí
 struct nodo *sig; // puntero autoreferencial
                   // al proximo nodo
} tNodo;

//Estructura de la lista:
typedef struct Lista{
 tNodo *head; //Primer elemento
 tNodo *tail; //Ultimo elemento
 tNodo *curr; //Elemento actual
 long unsigned int listSize; //Tamaño de la lista
 long unsigned int pos; // Posición actual en la lista
} tLista;

typedef struct grafo{
    tLista *lista; //puntero a la lista
    long int vertice; //numero de vertices
    long int arcos; //numero de arcos
} tGrafo;


// crea la lista LISTO
tLista *crearLista();
// borra todos los elementos de la lista, reinicializándola vacía D
void clear (tLista*);
// inserta un elemento en la posición actual de la lista S LISTO
int insert (tLista*,elemento);
// agrega un elemento al final de la lista LISTO
int append (tLista*,elemento);
// borra el elemento actual y retorna su valor  F LISTO
elemento lremove (tLista*);
// mueve la posición actual al comienzo de la lista D LISTO
void moveToStart (tLista*);
// mueve la posición actual al final de la lista S LISTO
void moveToEnd (tLista*);
// mueve la posición actual al siguiente elemento de la lista.
// No produce cambios si está en la cabeza de la lista F LISTO
int next (tLista*);
// mueve la posición actual al elemento anterior de la lista.
// No produce cambios si está en la cola de la lista D LISTO
void prev (tLista*);
// retorna el número de elementos en la lista s LISTO
int length (tLista*);
// retorna la posición del elemento actual F LISTO
int currPos (tLista*);
// mueve la posición actual a una especificada D(puede no necesario)
void moveToPos (tLista*,int);
// obtiene el valor del elemento actual de la lista S LISTO
elemento getValue (tLista*);
// imprime la lista F
void Print(tLista *); 
// imprime un elemento F
void Printelemento(elemento);
// Resetea la Lista l
void clearL(tLista*);


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
tNodo nextg (tNodo v); 
// devuelve el vecino siguiente (i+1) a uno dado (i).
// Retorna el numero total de vertices si es que no existe--D
tNodo first (tGrafo *G, long int i); 
// agrega un nuevo arco al grafo entre vertices v1 y v2 (no se
// pueden agregar nuevos vertices)--S
void setEdge (tGrafo *G, long int v1, long int v2); 
// obtiene la marca asignada a un vertice dado (ciertos algoritmos
// necesitan marcar los vertices)---F
long int getMark ( tNodo v); 
// marca un vertice con un valor dado---D
void setMark (tGrafo *G, tNodo v, int marca); 


#endif
