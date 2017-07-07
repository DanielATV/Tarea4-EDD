#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafo.h"

int main(){
    long int num_ciuds;
    long int num_caminos;

    long int consultas;

    long int num_amigos, k,i,cont;
    long int *ciudades;
    long int ciudad_cumple;
    tNodo *z,*w;
    long int marca_actual,menor;
    long int aux1,aux2;
    tGrafo *G;
    //pide el numero de ciudades(nodos) y caminos para trabajar.
    scanf("%li",&num_ciuds);
    scanf("%li",&num_caminos);

    G =initGraph(num_ciuds);
    for (i=0; i < num_caminos;i++){
        scanf("%ld %ld",&aux1,&aux2);
        setEdge(G,aux1,aux2);
    }
    //Aca empiezan las consultas
    scanf("%li",&consultas);
    printf("%ld\n",consultas );
    for (i=0;i<consultas;i++){

        ciudad_cumple = num_ciuds;
        marca_actual = num_ciuds-1;
        scanf("%li",&num_amigos);

        ciudades = (long int*)malloc(sizeof(long int)*num_amigos);

        for(k=0;k<num_amigos;k++){
            scanf(" %ld",&ciudades[k]);
            setMark(G,posG(G,ciudades[k]),-1);
            if (nVecinos(G,ciudades[k]) < marca_actual){
               marca_actual = nVecinos(G,ciudades[k]);
               menor = ciudades[k];
             }
        }

        for (z=first(G,menor);z != NULL;z = nextg(z)){

            if((getMark(G,z) !=-1) && nVecinos(G,CNodo(z)) >= num_amigos){
                cont = 0;
                for(w= first(G,CNodo(z));w != NULL; w =nextg(w))
                  if(getMark(G,w) == -1) cont ++;
                if (cont == num_amigos)
                    ciudad_cumple = CNodo(z);
            }
        }
        // reseteamos las marcas para la siguiente peticion
        for(k=0;k<num_amigos;k++){
            setMark(G,posG(G,ciudades[k]),0);
        }
        //aca imprime en pantalla la ciudad que cumple
        printf("%li\n",ciudad_cumple);
        free((void *)ciudades);
    }

    destroyGraph(G);
    return 0;
}
