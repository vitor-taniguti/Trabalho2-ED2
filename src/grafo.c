#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int quantidadeVertices;
    int quantidadeVerticesInseridos;
    vertice* vertices;
    
    int quantidadeArestas;
    int quantidadeArestasInseridas;
    aresta* arestas;
} Grafo;

grafo criarGrafo(){
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));

    g->quantidadeVertices = 0;
    g->quantidadeVerticesInseridos = 0;
    g->vertices = NULL;
    
    g->quantidadeArestas = 2;
    g->quantidadeArestasInseridas = 0;
    g->arestas = malloc(2*sizeof(aresta));

    return g;
}

void setQuantidadeVerticesGrafo(grafo g, int quantidade){
    Grafo* grafo = (Grafo*) g;

    grafo->quantidadeVertices = quantidade;
    grafo->quantidadeVerticesInseridos = 0;

    grafo->vertices = (vertice*) malloc(quantidade * sizeof(vertice));
}

void inserirVerticeGrafo(grafo g, vertice v){
    Grafo* grafo = (Grafo*) g;

    if(grafo->quantidadeVerticesInseridos < grafo->quantidadeVertices){
        grafo->vertices[grafo->quantidadeVerticesInseridos] = v;
        grafo->quantidadeVerticesInseridos++;
    } else printf("Quantidade máxima de vértices atingida.\n");
}

void inserirArestaGrafo(grafo g, aresta a){
    Grafo* grafo = (Grafo*) g;

    if (grafo->quantidadeArestas >= grafo->quantidadeArestasInseridas) {
        grafo->quantidadeArestas *= 2;
        grafo->arestas = (aresta*) malloc(sizeof(aresta) * (grafo->quantidadeArestas));
    }
    grafo->arestas[grafo->quantidadeArestasInseridas] = a;
    grafo->quantidadeArestasInseridas++;
}

vertice buscarVerticeGrafo(grafo g, char* id){
    Grafo* grafo = (Grafo*) g;

    for(int i = 0; i < grafo->quantidadeVerticesInseridos; i++){
        vertice v = grafo->vertices[i];
        char* idVertice = getIdVertice(v);

        if(strcmp(idVertice, id) == 0) return v;
    }

    return NULL; 
}