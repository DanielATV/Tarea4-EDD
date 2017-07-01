#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafo.h"
int main(){
	/*
	int num_ciuds;
	int num_caminos;
	scanf("%d",&num_ciuds);
	scanf("%d",&num_caminos);
	
	int i,aux1,aux2;
	
	tGrafo *G;
	for (i=0; i < num_caminos;i++)
	{
		
		scanf("%d %d",&aux1,&aux2);
		//cambiar esto..
		setEdge(G,aux1,aux2);

	}

	int consultas, j;
	scanf("%d",&consultas);
	printf(consultas);
	for (j=0,j<consultas;j++)
	{
		//FALTA SCANEAR NUM AMIGOS ... Y LOS QUE SIGUEN
		char *consulta;
		scanf("%s",consulta);
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
	
	
	
	//realizar operaciones que digan si cumple o no y la ciudad que cumpla si hay

	
	printf("%d\n",consultas);
	if (cumple) printf("%d\n",ciudad_cumple\n);
	else	printf("%d\n",num_ciuds);
	*/
	return 0;


}
