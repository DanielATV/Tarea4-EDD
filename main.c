#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafo.h"

int main(){

	long int num_ciuds;
	long int num_caminos;
	scanf("%li",&num_ciuds);
	scanf("%li",&num_caminos);

	long int i,aux1,aux2;

	tGrafo *G;
	G =initGraph(num_ciuds);
	for (i=0; i < num_caminos;i++)
	{

		scanf("%li %li",&aux1,&aux2);
		setEdge(G,aux1,aux2);

	}

	long int consultas, j;
	scanf("%li",&consultas);

	int cumple;
	long int num_amigos, k;
	long int *ciudades;
	long int ciudad_cumple;
	long int maxmarca = 0;
	tNodo *z;
	long int marca_actual;
	for (j=0;j<consultas;j++)
	{

		ciudad_cumple =-1;


		scanf("%li",&num_amigos);


		ciudades = (long int*)malloc(sizeof(long int)*num_amigos);

		for(k=0;k<num_amigos;k++)
		{
			scanf(" %li",&ciudades[k]);
			setMark(G,ciudades[k],-1);
		}
		//printf("Las ciudades son: ");

		for (k=0;k<num_amigos;k++)
		{
			tLista *l = G->lista[ciudades[k]];
			for (z=first(G,ciudades[k]);z != NULL;z = nextg(z))
			{
				marca_actual = getMark(G,ciudades[l[z]]);
				marca_actual +=1;
				setMark(G,ciudades[l[z]],marca_actual);
				if (marca_actual > maxmarca)
				{
					maxmarca = marca_actual;
					ciudad_cumple = ciudades[l[z]];
				}


			}
			// aca no se -------------------------------------------**************************************
		}

		/*
		for (z=0;z<num_ciuds;z++)
		{
			marca_actual=0;
			setMark(G,z,marca_actual);
			for (k=0;k<num_amigos;k++)
			{
				if (z!= ciudades[k])
				{

					marca_actual++;
					setMark(G,z,marca_actual);


					if (marca_actual==num_amigos)
					{
						ciudad_cumple=z;
					}

				}
			}
		}
		*/

		printf("resultado");
		if (ciudad_cumple!=-1)
			printf("%li\n",ciudad_cumple);
		else	printf("%li\n",num_ciuds);

	}






	//printf("%li\n",consultas);
	/*
	if (cumple) printf("%li\n",ciudad_cumple);
	else	printf("%li\n",num_ciuds);
	*/
	return 0;


}
