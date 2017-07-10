#ifndef __lista_h__
#define __lista_h__

typedef struct elemento{
    long int ciudad;
} elemento;

typedef struct nodo {
    elemento info; // el elemento en sí
    struct nodo *sig; // puntero autoreferencial al proximo nodo
} tNodo;

//Estructura de la lista:
typedef struct Lista{
    tNodo *head; //Primer elemento
    tNodo *tail; //Ultimo elemento
    tNodo *curr; //Elemento actual
    long int listSize; //Tamaño de la lista
    long int pos; // Posición actual en la lista
    long int mark; //marca
} tLista;

// crea la lista
tLista *crearLista();
// borra todos los elementos de la lista, reinicializándola vacía 
void clear (tLista*);
// inserta un elemento en la posición actual de la lista 
int insert (tLista*,elemento);
// agrega un elemento al final de la lista
int append (tLista*,elemento);
// borra el elemento actual y retorna su valor
// mueve la posición actual al comienzo de la lista 
void moveToStart (tLista*);
// mueve la posición actual al final de la lista
void moveToEnd (tLista*);
// mueve la posición actual al siguiente elemento de la lista.
// No produce cambios si está en la cabeza de la lista 
int next (tLista*);
// mueve la posición actual al elemento anterior de la lista.
// No produce cambios si está en la cola de la lista
void prev (tLista*);
// retorna el número de elementos en la lista
long int length (tLista*);
// retorna la posición del elemento actual
long int currPos (tLista*);
// mueve la posición actual a una especificada
void moveToPos (tLista*,int);
// obtiene el valor del elemento actual de la lista
elemento getValue (tLista*);
// imprime la lista
void clearL(tLista*);
//realiza la Intersection entre dos listas
tLista *Intersection(tLista *,tLista *);
//realiza una copia de una lista dada
tLista *cpyL(tLista *);
#endif
