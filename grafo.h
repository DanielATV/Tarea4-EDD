//TDA Grafo

typedef struct grafo{
    tLista *lista; //puntero a 
    long int vertice; //numero de vertices
    long int arcos; //numero de arcos
} tGrafo;

// inicializa un grafo para n vértices--S
void initGraph (tGrafo *G, long int n); 
// libera la memoria utilizada por un grafo--F
void destroyGraph (tGrafo *G); 
// retorna el número de vértices en el grafo--D
long int nVertex (tGrafo *G); 
// retorna el número de arcos en el grafo--S
long int nEdges (tGrafo *G); 
// Devuelve el primer vecino de un vértice v dado (asume que los
// vecinos de un vértice están ordenados por número de vértice)--D
tNodo next(tVertice v); 
// devuelve el vecino siguiente (i+1) a uno dado (i).
// Retorna el número total de vértices si es que no existe--D
tNodo first (tGrafo *G, long int i); 
// agrega un nuevo arco al grafo entre vértices v1 y v2 (no se
// pueden agregar nuevos vértices)--S
void setEdge (tGrafo *G, long int v1, long int v2); 
// obtiene la marca asignada a un vértice dado (ciertos algoritmos
// necesitan marcar los vértices)---F
long int getMark (tGrafo *G, tNodo v); 
// marca un vértice con un valor dado---D
void setMark (tGrafo *G, tVertice v, int marca); D
