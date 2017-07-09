#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

//Crea una lista, mark es por si se trabaja para grafos
tLista *crearLista(){
	tLista* nueva = (tLista *) malloc(sizeof(tLista));
	tNodo* dummy = (tNodo *)malloc(sizeof(tNodo));

	dummy -> sig = NULL;
	nueva -> mark = -1;
	nueva -> head = dummy;
	nueva -> tail = dummy;
	nueva -> curr = dummy;
	nueva -> listSize = 0;
	nueva -> pos = 0;
	return nueva;
}
//inserta un elemento en una lista l, en la posicion actual
int insert(tLista *l, elemento item){
	tNodo *aux;

	aux = l->curr->sig;
	l->curr->sig = (tNodo *)malloc(sizeof(tNodo));

	if (l->curr->sig == NULL){
		l->curr->sig = aux;
		return 1; //Retorna 1 si falla.
	}
	l->curr->sig->info = item;
	l->curr->sig->sig = aux;
	if(l->curr == l->tail) l->tail = l->curr->sig;
	l->listSize++;
	return 0; //La operacion ocurrio con exito
}
//agrega un elemento al final de la lista
int append(tLista *l, elemento item){
	tNodo *temp = (tNodo*)malloc(sizeof(tNodo));
	if (temp==NULL) return 1;
	else
		temp->info = item;
		temp->sig = NULL;
		if (l->head == NULL) l->head = temp;
		else
		{
			tNodo *temp2= l->head;
			while(temp2->sig!=NULL)
			{
				temp2=temp2->sig;
			}
			temp2->sig = temp;
		}
		l->listSize++;
		return 0;
}
//elimina el elemento actual de la lista
elemento lremove(tLista *l){
	elemento item = l->curr->sig->info;
	if (l->curr->sig->sig == NULL){
		l->tail = l->curr;
		l->curr->sig = NULL;
	}
	else{
		l->curr->sig = l->curr->sig->sig;
	}
	l->pos --;
	l->listSize--;
	return item;
}
//mueve el cursor de la lista al inicio
void moveToStart(tLista* l){
	l -> pos = 0;
	l -> curr = l -> head;
}
//se mueve atras en la lista, notas que no es muy eficiente puesto que es lista
//enlazada, no doble enlazada, no hace nada si nos encontramos en el inicio
void prev (tLista* l){
	tNodo *aux = l->head;
	while(aux->sig != l->curr){
		aux = aux->sig;
	}
	l->curr = aux;
	l->pos = (l->pos)-1;
}
//mueve el cursor al final de la lista
void movetoEnd(tLista *l){
	l->curr = l->tail;
	l->pos = l->listSize -1;
}
//su mueve una posicion adelante
int next(tLista *l)
{
	if(l->curr->sig != l->tail)
	{
		l->curr = l->curr->sig;
		l->pos++;
		return 0;
	}
	else{
		l->pos++;
		return 0;
	}
}
//entrega el largo de la lista
long int length(tLista *l){
	return l->listSize;
}
//entrega la posicion actual de la lista
long int currPos(tLista *l){
	return l->pos;
}
//entrega el elemento actual de la lista
elemento getValue(tLista *l){
	return l->curr->sig->info;
}
//elimina la lista y elimina todos sus punteros
void clearL(tLista *l){
	int i;
	tNodo *aux2, *aux;
	aux = l->head->sig;
	for(i =0; i < l->listSize ;i++){
		aux2 = aux->sig;
		free((void *)aux);
		aux = aux2;
	}
	free((void *)l->head);
	free((void *)l);
}
//agrega un elemento en la posicion actual de la lista y lo hace manteniendo orden creciente
int insort(tLista *l, elemento item){
	tNodo *aux;
	if(l->curr->sig != NULL){
		moveToStart(l);
		while(l->pos < l->listSize){
			if(item.ciudad > getValue(l).ciudad) next(l);
			else break;
		}
		aux = l->curr->sig;
		l->curr->sig = (tNodo *)malloc(sizeof(tNodo));

		l->curr->sig->info = item;
		l->curr->sig->sig = aux;
		if(l->curr == l->tail) l->tail = l->curr->sig;
		l->listSize++;
		return 0; //La operacion ocurrio con exito

	}
	else{
		aux = l->curr->sig;
		l->curr->sig = (tNodo *)malloc(sizeof(tNodo));

		l->curr->sig->info = item;
		l->curr->sig->sig = aux;
		if(l->curr == l->tail) l->tail = l->curr->sig;
		l->listSize++;
		return 0; //La operacion ocurrio con exito
	}
}/*****
* tLista *Intersection
******
* Dada dos listas, entrega una puntero a una nueva lista con los elementos comunes.
******
* Input:
* tLista *A : Primera lista que se desea comparar.
* tLista *B : Segunda lista que se desea comparar.
******
* Returns:
* tLista *, puntero a la nueva lista con elementos comunes.
*****/
//entrega una lista correspondiente a la interseccion de dos litas
// la lista tendra largo 0 si no hay elementos en comun
tLista *Intersection(tLista *A,tLista *B){
	tLista *C; //sera la lista que entregue
	C = crearLista();
	for(moveToStart(A); currPos(A) < length(A); next(A))
		for(moveToStart(B); currPos(B) < length(B); next(B))
			if( getValue(A).ciudad == getValue(B).ciudad) insert(C, getValue(A));
	clearL(A);
	return C;
}
//realiza una copia de una lista, copia los elementos por lo que no comparte punteros
tLista *cpyL(tLista *l){
	tLista *aux;
	aux = crearLista();
	for(moveToStart(l); currPos(l) < length(l); next(l))
		insert(aux, getValue(l));
	return aux;
}
