#include <stdio.h>
#include <stdlib.h>
//#include "heap.h"
//#include "heap.c"

int main(){
	int num_ciuds;
	int num_caminos;
	scanf("%d",&num_ciuds);
	scanf("%d",&num_caminos);
	
	int i,aux1,aux2;
	for (i=0; i < num_caminos;i++)
	{
		
		scanf("%d %d",&aux1,&aux2);
		//cambiar esto..
		setEdge(G,G.lista[aux1],G.lista[aux2]);

	}

	int consultas;
	scanf("%d",&consultas);

	int ciudad_cumple;	
	bool cumple = 0; //false

	//realizar operaciones que digan si cumple o no y la ciudad que cumpla si hay

	
	printf("%d\n",consultas);
	if (cumple) printf("%d\n",ciudad_cumple\n);
	else	printf("%d\n",num_ciuds);
	
	return 0;


}
