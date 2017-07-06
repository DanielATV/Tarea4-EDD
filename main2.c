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
	scanf("%li",&num_ciuds);
	scanf("%li",&num_caminos);

	G =initGraph(num_ciuds);
	long int min_marca;
	long int *origenes = (long int*)malloc(sizeof(long int)*num_ciuds);
	long int *destinos = (long int*)malloc(sizeof(long int)*num_ciuds);
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

		ciudad_cumple = num_ciuds;
		scanf("%li",&num_amigos);

		ciudades = (long int*)malloc(sizeof(long int)*num_amigos);

		for(k=0;k<num_amigos;k++){
			scanf(" %ld",&ciudades[k]);
			setMark(G,ciudades[k],-1);
		}
		for(m = 0;m<num_ciuds;m++)
		{

			if (getMark(G,origenes[m])==-1	&& getMark(G,destinos[m])!=-1)
			{
				marca_actual = getMark(G,destinos[m]);
				setMark(G,destinos[m],marca_actual+1);
				marca_actual =0;
			}	
			else if (getMark(G,origenes[m]) !=-1	&& getMark(G,destinos[m])== 1)
			{
				marca_actual = getMark(G,origenes[m]);
				setMark(G,origenes[m],marca_actual+1);
				marca_actual =0;
			}
		}
		for (z=first(G,ciudades[0]);z != NULL ; z = nextg(z) )
		{
			
			if(getMark(G,z->info.ciudad) >= num_amigos && getMark(G,z->info.ciudad) < min_marca )
			{
				min_marca = getMark(G,z->info.ciudad);
				ciudad_cumple = z->info.ciudad;
				
			}
		
		}


		/*
		for (z=first(G,ciudades[0]);z != NULL;z = nextg(z))
		{

			if((getMark(G,z->info.ciudad) !=-1) && (ciudad_cumple > z->info.ciudad))
			{
				cont = 0;
				for(w= first(G,z->info.ciudad);w != NULL; w =nextg(w)) 
					if(getMark(G,w->info.ciudad) == -1) 
					{
						cont ++;
					}
				if (cont == num_amigos)
				{
					ciudad_cumple = z->info.ciudad;
				}
			}
		}
		*/
        // reseteamos las marcas para la siguiente peticion
		for(k=0;k<num_amigos;k++){
			setMark(G,ciudades[k],0);
		}
        //aca imprime en pantalla la ciudad que cumple
		printf("%li\n",ciudad_cumple);
		free((void *)ciudades);
		free((void *)origenes);
		free((void *)destinos);
    	}

	destroyGraph(G);
	return 0;
}

