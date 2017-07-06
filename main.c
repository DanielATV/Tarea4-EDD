#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafo.h"

int main(){
	long int num_ciuds;
	long int num_caminos;

	long int consultas;

	long int num_amigos, k,i;
	long int ciudades;
	long int ciudad_cumple;
	long int maxmarca;
	tNodo *z;
	long int marca_actual;

	long int aux1,aux2;

	tGrafo *G;
	//pide el numero de ciudades(nodos) y caminos para trabajar.
	scanf("%li",&num_ciuds);
	scanf("%li",&num_caminos);

	G =initGraph(num_ciuds);
	for (i=0; i < num_caminos;i++){
		scanf("%li %li",&aux1,&aux2);
		setEdge(G,aux1,aux2);
	}
	resetMark(G);
	//Aca empiezan las consultas
	scanf("%li",&consultas);
	printf("%ld\n",consultas );
	for (i=0;i<consultas;i++){
		ciudad_cumple =-1;
		maxmarca = 0;

		scanf("%li",&num_amigos);

		for(k=0;k<num_amigos;k++)
		{
			scanf(" %li",&ciudades);
			setMark(G,ciudades,-1);

			for (z=first(G,ciudades);z != NULL;z = nextg(z)){
				marca_actual = getMark(G,z->info.ciudad);
				if (marca_actual != -1) {
					marca_actual +=1;
					setMark(G,z->info.ciudad,marca_actual);
					if (marca_actual == maxmarca && ciudad_cumple > z->info.ciudad){
						ciudad_cumple = z->info.ciudad;
					}
					else if (marca_actual > maxmarca){
						maxmarca = marca_actual;
						ciudad_cumple = z->info.ciudad;
					}
				}
			}

		}
		//aca imprime en pantalla la ciudad que cumple
		if (maxmarca == num_amigos)printf("%li\n",ciudad_cumple);
		else	printf("%li\n",num_ciuds); // si ninguna cumple, printea el num de ciudades.

		 // reseteamos las marcas para la siguiente peticion
	}

	destroyGraph(G);
	return 0;
}
