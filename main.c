#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "grafo.h"

//lo uso para hacer pruebas
int main(){
	long int i;
	tGrafo *G;
	tNodo *w;
	i = 10000;
	G = initGraph(i); //crea el grafo
	printf("%ld\n",nVertex(G));
	setMark(G,12,1234);
	setEdge(G,14,12);
	//basicamente recorro los vecinos de 14 para ver sus marcas, de esa forma ver
	// si la marca de 12 es la misma.
	for(w = first(G,14);w != NULL; w = nextg(w)) printf("%ld\n", getMark(w));
	//printf("%ld\n",getMark() ); // esto es lo que te dije Fabian, quiero ver la
	//marca de 12 pero no se como
	printf("%ld\n",nEdges(G));
	destroyGraph(G);
	return 0;


}
