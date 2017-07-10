#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
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
    
    /* Declaracion de variables */
    long int num_ciuds;
    long int num_caminos;
    long int consultas;
    long int num_amigos, k,i;
    long int ciudad;
    long int ciudad_cumple;
    long int aux1,aux2;
    tGrafo *G;
    tLista *inter;
   
    /* Creacion del grafo */
    scanf("%li\n",&num_ciuds);
    G =initGraph(num_ciuds);
    
    /* Adicion de los arcos */
    scanf("%li\n",&num_caminos);
    for (i=0; i < num_caminos;i++){
        scanf("%ld %ld\n",&aux1,&aux2);
        setEdge(G,aux1,aux2);
    }

     /* Procesamiento de las consultas */
    scanf("%li\n",&consultas);
    printf("%ld\n",consultas );
    
    for (i = 0 ; i < consultas ; i++){
        
        /* Output en el caso de ser vacia la interseccion */
        ciudad_cumple = num_ciuds;
        scanf("%li",&num_amigos);
        scanf("%ld",&ciudad);
        
        /* Obtencion de la los vecinos del primer amigo */
        inter = cpyL(Vecinos(G, ciudad));

        /* Se realiza la interseccion de los vecinos de todos los amigos */
        for(k = 0; k < num_amigos -1 ; k++){
            scanf(" %ld",&ciudad);
            inter = Intersection(inter,Vecinos(G,ciudad));
        }

        /* Se busca el menor de la interseccion */
        if(length(inter) != 0){
            for (moveToStart(inter); currPos(inter) < length(inter); next(inter)){
                if (getValue(inter).ciudad < ciudad_cumple) ciudad_cumple = getValue(inter).ciudad;
            }
        }
        
        /* Output del problema */
        printf("%li\n",ciudad_cumple);
        
        /* Liberacion de memoria de la lista */
        clearL(inter);
    }
    
    /* Liberacion de memoria del grafo */
    destroyGraph(G);
    return 0;
}
