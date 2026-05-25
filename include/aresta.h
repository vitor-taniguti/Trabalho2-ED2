#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

typedef void *aresta;

/// @brief Cria o objeto aresta com os atributos especificados
/// @param v1 Primeiro vértice da aresta
/// @param v2 Segundo vértice da aresta
/// @param ldir CEP da quadra que está do lado direito do segmento de rua
/// @param lesq CEP da quadra que está do lado esquerdo do segmento de rua
/// @param cmp Comprimento da aresta
/// @param vm Velocidade média da aresta
/// @param nome Nome da rua a qual pertence o segmento
/// @return Ponteiro para o objeto aresta criado
aresta criarAresta(vertice* v1, vertice* v2, char* ldir, char* lesq, double cmp, double vm, char* nome);

/// @brief Pega o primeiro vértice da aresta
/// @param a Ponteiro para a aresta que o vértice será pego
/// @return Ponteiro para o primeiro vértice da aresta
vertice getV1Aresta(aresta a);

/// @brief Pega o segundo vértice da aresta
/// @param a Ponteiro para a aresta que o vértice será pego
/// @return Ponteiro para o segundo vértice da aresta
vertice getV2Aresta(aresta a);

/// @brief Pega o CEP da quadra que está do lado direito do segmento de rua
/// @param a Ponteiro para aresta que o CEP será pego
/// @return CEP da quadra que está do lado direito do segmento de rua
char* getLdirAresta(aresta a);

/// @brief Pega o CEP da quadra que está do lado esquerdo do segmento de rua
/// @param a Ponteiro para aresta que o CEP será pego
/// @return CEP da quadra que está do lado esquerdo do segmento de rua
char* getLesqAresta(aresta a);

/// @brief Pega o comprimento da aresta
/// @param a Ponteiro para a aresta que o comprimento será pego
/// @return Comprimento da aresta
double getCmpAresta(aresta a);

/// @brief Pega a velocidade média da aresta
/// @param a Ponteiro para a aresta que a velocidade será pega
/// @return Velocidade média da aresta
double getVmAresta(aresta a);

/// @brief Pega o nome da rua a qual pertence o segmento
/// @param a Ponteiro para a aresta que o nome será pego
/// @return Nome da rua a qual pertence o segmento
char* getNomeAresta(aresta a);

/// @brief Define o CEP da quadra que está do lado direito do segmento
/// @param a Ponteiro para a aresta que o CEP será definido
/// @param ldir CEP da quadra que está do lado direito do segmento de rua
void setLdirAresta(aresta a, char* ldir);

/// @brief Define o CEP da quadra que está do lado esquerdo do segmento
/// @param a Ponteiro para a aresta que o CEP será definido
/// @param lesq CEP da quadra que está do lado esquerdo do segmento de rua
void setLesqAresta(aresta a, char* lesq);

/// @brief Define o comprimento da aresta
/// @param a Ponteiro para a aresta que o comprimento será definido
/// @param cmp Comprimento da aresta
void setCmpAresta(aresta a, double cmp);

/// @brief Define a velocidade média da aresta
/// @param a Ponteiro para a aresta que a velocidade média será definida
/// @param vm Velocidade média da aresta
void setVmAresta(aresta a, double vm);

#endif