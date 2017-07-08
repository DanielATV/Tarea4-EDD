#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(){
    long int num_ciuds;
    long int num_caminos;

    long int consultas;

    long int num_amigos, k,i;
    long int ciudad;
    long int ciudad_cumple;
    long int aux1,aux2;
    tGrafo *G;
    tLista *inter;
    //pide el numero de ciudades(nodos) y caminos para trabajar.
    scanf("%li\n",&num_ciuds);
    G =initGraph(num_ciuds);
    //ahora crea los caminos
    scanf("%li\n",&num_caminos);
    for (i=0; i < num_caminos;i++){
        scanf("%ld %ld\n",&aux1,&aux2);
        setEdge(G,aux1,aux2);
    }
    //Aca empiezan las consultas!!
    scanf("%li\n",&consultas);
    printf("%ld\n",consultas );

    for (i = 0 ; i < consultas ; i++){

        ciudad_cumple = num_ciuds; //lo definimos de esta manera para si nadie
        //cumple no haga cambios
        scanf("%li",&num_amigos);
        //para el primero lo pido aparte para crear la lista inicial de personas
        scanf("%ld",&ciudad);
        inter = Vecinos(G, ciudad); //de esta manera tengo con quien hacer interseccion
        for(k = 0; k < num_amigos -1 ; k++){
            scanf(" %ld",&ciudad);
            inter = Intersection(inter,Vecinos(G,ciudad));

        }
        //si algun valor sobrevive despues de la interseccion se busca el menor
        //de ellos para ser la ciudad que cumpla
        if(length(inter) != 0)
          for (moveToStart(inter); currPos(inter) < length(inter); next(inter))
            if (getValue(inter).ciudad < ciudad_cumple)
              ciudad_cumple = getValue(inter).ciudad;
              
        //aca imprime en pantalla la ciudad que cumple
        printf("%li\n",ciudad_cumple); //no necesita condiciones, porque si nadie
        //cumple ciudad_cumple predeterminadamente sera la cantidad de ciudades
        clearL(inter);
    }

    destroyGraph(G);
    return 0;
}
