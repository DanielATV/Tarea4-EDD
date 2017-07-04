#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafo.h"

int main(){

	/*
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
	//for(w = first(G,14);w != NULL; w = nextg(w)) printf("%ld\n", getMark(w));
	//printf("%ld\n",getMark() ); // esto es lo que te dije Fabian, quiero ver la
	//marca de 12 pero no se como
	printf("%ld\n",nEdges(G));



	printf("%ld\n", getMark(G,12) );
	destroyGraph(G);
	return 0;
	*/

	
	
	long int num_ciuds;
	long int num_caminos;
	scanf("%li",&num_ciuds);
	scanf("%li",&num_caminos);
	
	printf("el grafo tiene %li ciudades y %li caminos \n\n",num_ciuds,num_caminos);
	long int i,aux1,aux2;
	
	tGrafo *G;
	G =initGraph(num_ciuds);
	for (i=0; i < num_caminos;i++)
	{
		
		scanf("%li %li",&aux1,&aux2);
		//cambiar esto..
		setEdge(G,aux1,aux2);
		printf("agregado arco %li - %li \n",aux1,aux2);

	}

	long int consultas, j;
	scanf("%li",&consultas);
	printf("numero consultas: %li\n",consultas);

	int cumple;
	long int num_amigos, k;
	long int *ciudades;
	long int ciudad_cumple;	
	long int maxmarca = 0;
	long int z;
	for (j=0;j<consultas;j++)
	{
		printf("Consulta: %li\n ",j);
		
		scanf("%li",&num_amigos);
		
		
		ciudades = (long int*)malloc(sizeof(long int)*num_amigos);
		for(k=0;k<num_amigos;k++)
		{
			scanf(" %li",&ciudades[k]);
			
		}
		printf("Las ciudades son: ");
		for(k=0;k<num_amigos;k++)
		{
			

			printf("%li ",ciudades[k]);
			for (z=0;z<num_ciuds;<++)
			{
				if (z!=k)
				{
				
				}
			}
			
		}
		printf("\n");
		


		//------------------
		//AQUI HACER COSAS PARA MODIFICAR GRAFO

		//----------------
		

		cumple = 0; //false
		for (i = 0;i<num_amigos;i++)
		{
			if(getMark(G,i)>=maxmarca)
			{
				maxmarca = getMark(G,i);
				ciudad_cumple=i;

			}
		}		



		
		/*
		if (maxmarca==num_amigos)
			printf("%li\n",i);
		else	printf("%li\n",num_ciuds);
		*/
	}
	
	
	
	

	
	//printf("%li\n",consultas);
	/*
	if (cumple) printf("%li\n",ciudad_cumple);
	else	printf("%li\n",num_ciuds);
	*/
	return 0;


}
