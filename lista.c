#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

/*****
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
tLista *Intersection(tLista *A,tLista *B){
	tLista *C;
	C = crearLista();
	for(moveToStart(A); currPos(A) < length(A); next(A))
		for(moveToStart(B); currPos(B) < length(B); next(B))
			if( getValue(A).ciudad == getValue(B).ciudad) insert(C, getValue(A));
	return C;
}


//Crea una lista.
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
//Inserta un elemento a la lista.
int insert(tLista *l, elemento item){
	tNodo *aux;

	aux = l->curr->sig;
	l->curr->sig = (tNodo *)malloc(sizeof(tNodo));

	if (l->curr->sig == NULL){
		l->curr->sig = aux;
		return 1;
	}
	l->curr->sig->info = item;
	l->curr->sig->sig = aux;
	if(l->curr == l->tail) l->tail = l->curr->sig;
	l->listSize++;
	return 0; 
}
//Agrega un elemento al final de la lista.
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
//Elimina el elemento actual de la lista.
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
//Mueve el cursor de la lista al inicio.
void moveToStart(tLista* l){
	l -> pos = 0;
	l -> curr = l -> head;
}
//Se mueve al elemento anterior de la lista.
void prev (tLista* l){
	tNodo *aux = l->head;
	while(aux->sig != l->curr){
		aux = aux->sig;
	}
	l->curr = aux;
	l->pos = (l->pos)-1;
}
//Mueve el cursor al final de la lista.
void movetoEnd(tLista *l){
	l->curr = l->tail;
	l->pos = l->listSize -1;
}
//Se mueve una posicion adelante
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
//Entrega el largo de la lista.
long int length(tLista *l){
	return l->listSize;
}
//Entrega la posicion actual de la lista.
long int currPos(tLista *l){
	return l->pos;
}
//Entrega el elemento actual de la lista.
elemento getValue(tLista *l){
	return l->curr->sig->info;
}
//Elimina la lista y elimina todos sus punteros.
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

