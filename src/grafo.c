#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoAresta {
    aresta dadosAresta;       
    struct NoAresta* proximo; 
} NoAresta;

typedef struct {
    vertice v;             
    NoAresta* primeiraAresta; 
} VerticeInterno;

typedef struct {
    int quantidadeVertices;
    int quantidadeVerticesInseridos;
    VerticeInterno* vertices; 
} Grafo;

grafo criarGrafo(){
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));

    g->quantidadeVertices = 0;
    g->quantidadeVerticesInseridos = 0;
    g->vertices = NULL;

    return g;
}

void setQuantidadeVerticesGrafo(grafo g, int quantidade){
    Grafo* grafo = (Grafo*) g;

    grafo->quantidadeVertices = quantidade;
    grafo->quantidadeVerticesInseridos = 0;

    grafo->vertices = (VerticeInterno*) malloc(quantidade * sizeof(VerticeInterno));

    for (int i = 0; i < quantidade; i++) {
        grafo->vertices[i].v = NULL;        
        grafo->vertices[i].primeiraAresta = NULL;
    }
}

void inserirVerticeGrafo(grafo g, vertice v){
    Grafo* grafo = (Grafo*) g;

    if(grafo->quantidadeVerticesInseridos < grafo->quantidadeVertices){
        grafo->vertices[grafo->quantidadeVerticesInseridos].v = v;
        grafo->vertices[grafo->quantidadeVerticesInseridos].primeiraAresta = NULL;
        grafo->quantidadeVerticesInseridos++;
    } else printf("Quantidade máxima de vértices atingida.\n");
}

void inserirArestaGrafo(grafo g, aresta a){
    Grafo* grafo = (Grafo*) g;
    char* idOrigem = getIdOrigemAresta(a); 

    int indiceOrigem = -1;
    
    for (int i = 0; i < grafo->quantidadeVerticesInseridos; i++) {
        if (strcmp(getIdVertice(grafo->vertices[i].v), idOrigem) == 0) {
            indiceOrigem = i;
            break;
        }
    }

    if (indiceOrigem == -1) {
        printf("Erro: Vértice de origem da aresta não encontrado no grafo.\n");
        return;
    }

    NoAresta* novoNo = (NoAresta*) malloc(sizeof(NoAresta));
    novoNo->dadosAresta = a;

    novoNo->proximo = grafo->vertices[indiceOrigem].primeiraAresta;
    grafo->vertices[indiceOrigem].primeiraAresta = novoNo;
}

vertice buscarVerticeGrafo(grafo g, char* id){
    Grafo* grafo = (Grafo*) g;

    for(int i = 0; i < grafo->quantidadeVerticesInseridos; i++){
        vertice vAtual = grafo->vertices[i].v;
        char* idVertice = getIdVertice(vAtual); 

        if(strcmp(idVertice, id) == 0) return vAtual;
    }
    return NULL; 
}