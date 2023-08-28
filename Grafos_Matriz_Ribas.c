#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
    int v;
    int w;
}Edge;

typedef struct Graph{
    int v;
    int e;
    int **adj;
}Graph;

Edge Aresta(int v,int w){
}

Graph *cria_grafo(int numero_vertices){
    Graph *G = malloc(sizeof(*G));
    G->v = numero_vertices;
    G->e = 0;
    G->adj = matrix_init(numero_vertices,numero_vertices,0);
    return G;
}

void insere_no_grafo(Graph *grafo,Edge aresta){
    int v = aresta.v;
    int w = aresta.w;
    if(grafo->adj[v][w] == 0){
        grafo->e++;
    }
    grafo->adj[v][w] = 1;
    grafo->adj[w][v] = 1;

}

void remove_no_grafo(Graph *grafo,Edge aresta){
    int v = aresta.v;
    int w = aresta.w;
    if(grafo->adj[v][w] == 1){
        grafo->e--;
    }
    grafo->adj[v][w] = 0;
    grafo->adj[w][v] = 0;
}

int arestas_grafo(Edge aresta[],Graph *grafo){
    int v,w,E = 0;
    for(v=0;v<grafo->v;v++)
        for(w = v+1;w<grafo->v;w++){
            if(grafo->adj[v][w] == 1){
                aresta[E++] = Aresta(v,w);
            }
        }
    return E;
}
