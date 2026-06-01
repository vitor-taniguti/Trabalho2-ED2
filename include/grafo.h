#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"
#include "aresta.h"

typedef void* grafo;

/// @brief Cria um grafo
/// @return Ponteiro para o grafo criado
grafo criarGrafo();

/// @brief Define a quantidade de vértices do grafo
/// @param g Ponteiro para o grafo
/// @param quantidade Quantidade de vértices a ser definida
void setQuantidadeVerticesGrafo(grafo g, int quantidade);

/// @brief Insere o vértice no grafo
/// @param g Ponteiro para o grafo
/// @param vertice Ponteiro para o vértice a ser inserido
void inserirVerticeGrafo(grafo g, void* vertice);

/// @brief Insere a aresta no grafo
/// @param g Ponteiro para o grafo
/// @param aresta Ponteiro para a aresta a ser inserida
void inserirArestaGrafo(grafo g, void* aresta);

/// @brief Busca um vértice no grafo
/// @param g Ponteiro para o grafo
/// @param id ID do vértice a ser buscado
/// @return Ponteiro para o vértice encontrado ou NULL se não encontrado
vertice buscarVerticeGrafo(grafo g, char* id);

#endif