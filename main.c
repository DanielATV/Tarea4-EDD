#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafo.h"

int main(){
	long int num_ciuds;
	long int num_caminos;

	long int consultas;

	long int num_amigos, k;
	long int *ciudades;
	long int ciudad_cumple;
	long int maxmarca;
	tNodo *z;
	long int marca_actual;

	long int i,aux1,aux2;

	tGrafo *G;
	//pide el numero de ciudades(nodos) y caminos para
	scanf("%li",&num_ciuds);
	scanf("%li",&num_caminos);

	G =initGraph(num_ciuds);
	for (i=0; i < num_caminos;i++){
		scanf("%li %li",&aux1,&aux2);
		setEdge(G,aux1,aux2);
	}
	//Aca empiezan las consultas
	scanf("%li",&consultas);
	printf("%ld\n",consultas );
	for (i=0;i<consultas;i++){
		ciudad_cumple =-1;
		maxmarca = 0;

		scanf("%li",&num_amigos);

		ciudades = (long int*)malloc(sizeof(long int)*num_amigos);

		for(k=0;k<num_amigos;k++)
		{
			scanf(" %li",&ciudades[k]);
			setMark(G,ciudades[k],-1);

			for (z=first(G,ciudades[k]);z != NULL;z = nextg(z)){
				marca_actual = getMark(G,z->info.ciudad);
				if (marca_actual != -1) {
					marca_actual +=1;
					setMark(G,z->info.ciudad,marca_actual);
					if (marca_actual >= maxmarca && ciudad_cumple > z->info.ciudad){
						maxmarca = marca_actual;
						ciudad_cumple = z->info.ciudad;
					}
				}
			}

		}
		//aca imprime en pantalla la ciudad que cumple
		if (ciudad_cumple!=-1 && maxmarca == num_amigos)
			printf("%li\n",ciudad_cumple);
		else	printf("%li\n",num_ciuds); // si ninguna cumple, printea el num de ciudades.

		resetMark(G); // reseteamos las marcas para la siguiente peticion
		free((void *)ciudades); //liberamos la memoria del arreglo de ciudades
	}


	destroyGraph(G);
	return 0;
}
