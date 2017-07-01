TDA Grafo

typedef struct grafo{
    tLista *lista; //puntero a 
    long int vertice; //numero de vertices
    long int arcos; //numero de arcos
} tGrafo;

// inicializa un grafo para n vértices
void initGraph (tGrafo *G, int n); S
// libera la memoria utilizada por un grafo
void destroyGraph (tGrafo *G); F
// retorna el número de vértices en el grafo
int nVertex (tGrafo *G); D
// retorna el número de arcos en el grafo
int nEdges (tGrafo *G); S
// Devuelve el primer vecino de un vértice v dado (asume que los
// vecinos de un vértice están ordenados por número de vértice)
tVertice next(tVertice v); F
// devuelve el vecino siguiente (i+1) a uno dado (i).
// Retorna el número total de vértices si es que no existe
tVertice first (tGrafo *G, long int i); D
// agrega un nuevo arco al grafo entre vértices v1 y v2 (no se
// pueden agregar nuevos vértices)
void setEdge (tGrafo *G, tVertice v1, tVertice v2, int peso); S
// obtiene la marca asignada a un vértice dado (ciertos algoritmos
// necesitan marcar los vértices)
int getMark (tGrafo *G, tVertice v); F
// marca un vértice con un valor dado
void setMark (tGrafo *G, tVertice v, int marca); D
