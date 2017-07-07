#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafo.h"

int main()
{
	long int num_ciuds;
	long int num_caminos;

	long int consultas;

	long int num_amigos, k,i,cont, m;
	long int *ciudades;
	long int ciudad_cumple;
	tNodo *z,*w;
	long int marca_actual, max_marca;
	
	long int aux1,aux2;
	tGrafo *G;
	//pide el numero de ciudades(nodos) y caminos para trabajar.
	scanf("%ld",&num_ciuds);
	scanf("%li",&num_caminos);
	printf("asdaf1\n");
	G =initGraph(num_ciuds);
	printf("asdaf1.1\n");
	long int min_marca;
	long int *origenes = (long int*)malloc(sizeof(long int)*num_caminos);
	long int *destinos = (long int*)malloc(sizeof(long int)*num_caminos);
	printf("asdaf2\n");
	for (i=0; i < num_caminos;i++)
	{
		scanf("%ld %ld",&origenes[i],&destinos[i]);
		setEdge(G,origenes[i],destinos[i]);
	}
	//Aca empiezan las consultas
	scanf("%li",&consultas);
	printf("%ld\n",consultas );
	for (i=0;i<consultas;i++)
	{
		min_marca = num_ciuds;
		marca_actual=0;
		ciudad_cumple = num_ciuds;
		scanf("%li",&num_amigos);

		ciudades = (long int*)malloc(sizeof(long int)*num_amigos);

		for(k=0;k<num_amigos;k++){
			scanf(" %ld",&ciudades[k]);
			setMark(G,ciudades[k],-1);
		}
		for(m = 0;m<num_caminos;m++)
		{
			//printf("origen marca: %li, destino marca: %li \n",getMark(G,origenes[m]),getMark(G,destinos[m]));
			if (getMark(G,origenes[m])==-1	&& getMark(G,destinos[m])!=-1)
			{
				//printf("a\n");
				//printf("origen es: %li -- destino es:%li  \n",origenes[m],destinos[m]);
				marca_actual = getMark(G,destinos[m]);
				marca_actual++;
				setMark(G,destinos[m],marca_actual);
				
				
				
	
			
				
			}	
			else if (getMark(G,origenes[m]) !=-1	&& getMark(G,destinos[m])== -1)
			{
				//printf("b\n");
				//printf("origen es: %li -- destino es:%li  \n",origenes[m],destinos[m]);
				marca_actual = getMark(G,origenes[m]);
				marca_actual++;
				setMark(G,origenes[m],marca_actual);
				
				
			}

			
			if (marca_actual == num_amigos)
			{
				G->tiene=1;
			}
			marca_actual=0;
		}
		/*
		for(m = 0;m<num_ciuds;m++)
		{
			printf("    %li\n\n",getMark(G,m));
			
		}*/
		if (G->tiene==0)
		{
			printf("%li\n",num_ciuds);

		}
		else
			for (z=first(G,ciudades[0]);z != NULL ; z = nextg(z) )
			{
				//printf("-\n");
				//printf("vecino de 0: %li\n",z->info.ciudad);
			
				if(getMark(G,z->info.ciudad) == num_amigos && getMark(G,z->info.ciudad) < min_marca )
				{
					min_marca = getMark(G,z->info.ciudad);
					ciudad_cumple = z->info.ciudad;
					//printf("--\n");
				
				}
				//if (nextg(z) == NULL) 	z=NULL;
				//printf("asdafsd");
			}


		
        // reseteamos las marcas para la siguiente peticion
		for(k=0;k<num_ciuds;k++){
			setMark(G,k,0);
		}
        //aca imprime en pantalla la ciudad que cumple
		printf("%li\n",ciudad_cumple);
		free((void *)ciudades);
		
    	}
	free((void *)origenes);
	free((void *)destinos);
	//destroyGraph(G);
	

	return 0;
}

