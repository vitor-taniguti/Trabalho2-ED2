#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#include "vertice.h"

typedef void* filaPrioridade;

/// @brief Cria uma fila de prioridade
/// @return A fila de prioridade criada
filaPrioridade criarFilaPrioridade();

/// @brief Insere um elemento na fila de prioridade
/// @param f Ponteiro para a fila de prioridade
/// @param v Vértice que será inserido na fila de prioridade
/// @param prioridade Prioridade do elemento
void inserirFilaPrioridade(filaPrioridade f, vertice v, double prioridade);

/// @brief Extrai o elemento com menor prioridade da fila de prioridade
/// @param f Ponteiro para a fila de prioridade
/// @return O elemento com menor prioridade
vertice extrairMinimoFilaPrioridade(filaPrioridade f);

/// @brief Verifica se a fila de prioridade está vazia
/// @param f Ponteiro para a fila de prioridade
/// @return 1 se a fila estiver vazia, 0 caso contrário
int estaVaziaFilaPrioridade(filaPrioridade f);

/// @brief Libera a memória alocada para a fila de prioridade
/// @param f Ponteiro para a fila de prioridade
void liberarFilaPrioridade(filaPrioridade f);

#endif