#include "fab.h"
#include <stdlib.h>
#include <stdio.h>



//funciona
tLista *crearLista(){
	tLista* nueva = (tLista *) malloc(sizeof(tLista));
	tNodo* dummy = (tNodo *)malloc(sizeof(tNodo));
	dummy->sig = NULL;
	nueva->head = dummy;
	nueva->tail = dummy;
	nueva->curr = dummy;
	nueva->listSize = 0;
	nueva->pos = 0;
	return nueva;
}
//funciona
int insert(tLista *l, elemento item){
	tNodo *aux = l->curr->sig;
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
//funciona
int append(tLista *l, elemento item)
{
	tNodo *temp = (tNodo*)malloc(sizeof(tNodo));
	if (temp==NULL) return 1;
	else		
		//(*temp).data = x;
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
//funciona
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
//funciona
void moveToStart(tLista* l){
	l -> pos = 0;
	l -> curr = l -> head;
}
//funciona
void prev (tLista* l){
	
	tNodo *aux = l->head;
	
	while(aux->sig != l->curr){
		aux = aux->sig;
	
	}
	l->curr = aux;
	l->pos = (l->pos)-1;
}
//funciona
void movetoEnd(tLista *l){
	l->curr = l->tail;
	l->pos = l->listSize -1;
}
//funciona
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
//funciona
long int length(tLista *l){
	return l->listSize;
}
//funciona
long int currPos(tLista *l)
{	
	return l->pos;
}
//funciona
elemento getValue(tLista *l){
	return l->curr->sig->info;
}


//funciona
void clearL(tLista *l){
	int i;
	tNodo *aux = l->head->sig;
	tNodo *aux2;

	for(i =0; i < l->listSize ;i++){
		aux2 = aux->sig;
		free((void *)aux);
		aux = aux2;

	}
	
	l->head->sig = NULL;
	l->tail = l->head;
	l->curr = l->head;
	l->listSize = 0;
	l->pos = 0;
} 

#include "grafo.h"
#include "lista.h"

void initGraph(tGrado *G, int n){
	G->lista = (tLista *)malloc(sizeof(tLista)*n);
	G->vertices = 0;
	G->arcos = 0;
}

void destroyGraph (tGrafo *G)
{
	clearL(G->lista);
	G->vertice = 0;
	G->arcos = 0;
}

long int nVertex (tGrafo *G){
	int n;
	n = G -> vertices;
	return n;
}

long int nEdges(tGrafo *G){
	return G->arcos;
}

tNodo *nextg (tNodo *v)
{
	return v->sig;
}

tNodo *first (tGrafo *G, long int i){
	tNodo *np;
	np = G -> lista[i] -> head -> sig;
	return np;
}

void setEdge(tGrafo *G,long int v1,long int v2){
	elemento e1,e2;
	// modifico ambos elementos
	e1 -> pos = v1;
	e2 -> pos = v2;
	G -> arcos++; //aumento en 1 el numero de arcos
	//agrego ambos elementos
	append(G -> lista[v1], e2);
	append(G -> lista[v2], e1);
}

long int getMark (tNodo *v)
{
	return v->info->marca;
}

void setMark (tGrafo *G, long int i, long int marca){
	G -> lista[i] -> head -> info -> mark = marca;
}





