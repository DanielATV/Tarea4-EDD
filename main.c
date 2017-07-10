#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

/********************************************************
*El algoritmo desarrolado hace lo siguiente:            *
*Luego de crear el grafo, toma la primera ciudad de     *
*la consulta y obtiene la lista de sus vecinos,         *
*posteriomente toma la siguiente ciudad de la           *
*consulta, obtiene la lista de sus vecinos y se crea    *
*una nueva lista con los vecinos en comun de estos. Se  *
*repite este proceso para el resto de las ciudades de   *
*la consulta con la lista resultante en cada iteracion. *
*Si la interseccion resulta ser no vacia busca la menor,*
*en el caso contrario arroja el numero de ciudades del  *
*grafo.                                                 *
********************************************************/
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
    /* Creacion del grafo */
    scanf("%li\n",&num_ciuds);
    G =initGraph(num_ciuds);
    //ahora crea los caminos
    /* Adicion de los arcos */
    scanf("%li\n",&num_caminos);
    for (i=0; i < num_caminos;i++){
        scanf("%ld %ld\n",&aux1,&aux2);
        setEdge(G,aux1,aux2);
    }
    //Aca empiezan las consultas!!
     /* Procesamiento de las consultas */
    scanf("%li\n",&consultas);
    printf("%ld\n",consultas );
    for (i = 0 ; i < consultas ; i++){
        /* Output en el caso de ser vacia la interseccion */
        ciudad_cumple = num_ciuds; //lo definimos de esta manera para si nadie
        //cumple no haga cambios
        scanf("%li",&num_amigos);
        //para el primero lo pido aparte para crear la lista inicial de personas
        scanf("%ld",&ciudad);
        /* Obtencion de la los vecinos del primer amigo */
        inter = cpyL(Vecinos(G, ciudad)); //de esta manera tengo con quien hacer interseccion
        // ahora intersecto esta lista con los amigos
        /* Se realiza la interseccion de los vecinos de todos los amigos */
        for(k = 0; k < num_amigos -1 ; k++){
            scanf(" %ld",&ciudad);
            inter = Intersection(inter,Vecinos(G,ciudad));
        }
        //si algun valor sobrevive despues de la interseccion se busca el menor
        //de ellos para ser la ciudad que cumpla
        /* Se busca el menor de la interseccion */
        if(length(inter) != 0)
          for (moveToStart(inter); currPos(inter) < length(inter); next(inter))
            if (getValue(inter).ciudad < ciudad_cumple)
              ciudad_cumple = getValue(inter).ciudad;
        /* Output del problema */
        //aca imprime en pantalla la ciudad que cumple
        printf("%li\n",ciudad_cumple); //no necesita condiciones, porque si nadie
        //cumple ciudad_cumple predeterminadamente sera la cantidad de ciudades
        /* Liberacion de memoria de la lista */
        clearL(inter);
    }
    /* Liberacion de memoria del grafo */
    destroyGraph(G);
    return 0;
}
