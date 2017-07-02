#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafo.h"
int main(){
	
	long int num_ciuds;
	long int num_caminos;
	scanf("%d",&num_ciuds);
	scanf("%d",&num_caminos);
	
	long int i,aux1,aux2;
	
	tGrafo *G;
	for (i=0; i < num_caminos;i++)
	{
		
		scanf("%li %li",&aux1,&aux2);
		//cambiar esto..
		setEdge(G,aux1,aux2);

	}

	int consultas, j;
	scanf("%li",&consultas);
	printf(consultas);
	for (j=0,j<consultas;j++)
	{
		
		long int num_amigos, k;
		scanf("%li",&num_amigos);
		
		long int *ciudades;
		ciudades = (long int*)malloc(sizeof(long int)*num_amigos);
		for(k=0;k<num_amigos,k++)
		{
			scanf( "%li",&ciudades[k]);

		}

		//ACA SE TIENEN LAS CIUDADES		



		//------------------
		
		long int ciudad_cumple;	
		bool cumple = 0; //false
		long int num_vertices = nVertex(G);
		long int maxmarcas =0;
		for(i =0;i<num_vertices;i++){
			if (getMark(G[i])>=maxmarcas)
			{
				maxmarcas =getMark(G[i]); 
				ciudad_cumple=i;
			}
		}
		
		if (maxmarcas==num_amigos)
			printf("%d\n",i);
		else	printf("%d\n",num_ciuds);
	}
	
	
	
	

	
	printf("%d\n",consultas);
	if (cumple) printf("%d\n",ciudad_cumple\n);
	else	printf("%d\n",num_ciuds);
	
	return 0;


}
