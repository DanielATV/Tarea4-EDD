#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(){
    long int num_ciuds;
    long int num_caminos;

    long int consultas;

    long int num_amigos, k,i,cont;
    long int ciudades;
    long int ciudad_cumple;
    tNodo *z,*w;
    long int marca_actual,menor;
    long int aux1,aux2;
    tGrafo *G;
    //pide el numero de ciudades(nodos) y caminos para trabajar.
    scanf("%li\n",&num_ciuds);
    G =initGraph(num_ciuds);

    scanf("%li\n",&num_caminos);
    for (i=0; i < num_caminos;i++){
        scanf("%ld %ld\n",&aux1,&aux2);
        setEdge(G,aux1,aux2);
    }

    //Aca empiezan las consultas!!
    scanf("%li\n",&consultas);
    printf("%ld\n",consultas );

    for (i = 0 ; i < consultas ; i++){

        ciudad_cumple = num_ciuds;
        marca_actual = num_ciuds-1;
        scanf("%li",&num_amigos);

        for(k = 0; k < num_amigos ; k++){
            scanf(" %ld",&ciudades);
            setMark(G,posG(G,ciudades), i);
            if (nVecinos(G,ciudades) < marca_actual){
               marca_actual = nVecinos(G,ciudades);
               menor = ciudades;
             }
        }

        //ahora para el amigo con menos vecinos, recorro los vecinos
        for (z=first(G,menor);z != NULL;z = nextg(z)){
            //la idea es no recorrer un vecino que corresponda a uno de los amigos
            //y donde los vecinos de los vecinos del menor sean mas o iguales a
            //la cantidadde amigos sino no tiene sentido recorrerlo
            if((getMark(G,z) != i) && ((ciudad_cumple > CNodo(z)) && nVecinos(G,CNodo(z)) >= num_amigos)){
                cont = 0;
                for(w = first(G,CNodo(z)); w != NULL; w =nextg(w))
                  if(getMark(G,w) == i) cont ++;
                if (cont == num_amigos)
                  ciudad_cumple = CNodo(z);
            }
        }
        //aca imprime en pantalla la ciudad que cumple
        printf("%li\n",ciudad_cumple); //no necesita condiciones, porque si nadie
        //cumple ciudad_cumple predeterminadamente sera la cantidad de ciudades
    }

    destroyGraph(G);
    return 0;
}
