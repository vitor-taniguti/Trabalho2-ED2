#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include "quadra.h"

/*
Módulo responsável por gerenciar a estrutura de dado lista, incluindo suas operações de criar, inserir, remover, get e liberar memória.
*/

typedef FILE *arquivo;
typedef void *lista;
typedef void *iterador;

/// @brief Cria uma nova lista vazia
/// @return Ponteiro para a nova lista criada
lista criarLista();

/// @brief Insere um elemento no final da lista
/// @param l Ponteiro para a lista onde a quadraserá inserida
/// @param quadra q a ser inserida na lista
/// @param tipoquadraTipo da quadraa ser inserida na lista (1-Retângulo, 2-Círculo, 3-Linha, 4-Texto, 5-Anteparo, 6-Vértice)
void inserirLista(lista l, quadra q, int tipoQuadra);

/// @brief Remove o primeiro elemento da lista
/// @param l Ponteiro para a lista onde a quadraserá removida
/// @param i Ponteiro para o elemento que será apagado
void removerLista(lista l, iterador i);

/// @brief Busca o ponteiro para o elemento solicitado
/// @param l Ponteiro para a lista onde acontecerá a busca
/// @param alvo quadraque será buscada
/// @return Ponteiro para o elemento encontrado ou NULL se falhar
iterador buscarLista(lista l, quadra alvo);

/// @brief Pega o primeiro elemento da lista (sem remover)
/// @param l Ponteiro para a lista onde o elemento será pego
/// @return Ponteiro para o primeiro elemento ou NULL se estiver vazia
iterador getPrimeiroLista(lista l);

/// @brief Pega o proximo elemento da lista (sem remover)
/// @param i Elemento que o próximo elemento será pego
/// @return Ponteiro para o próximo elemento ou NULL se estiver vazia
iterador getProximoLista(iterador i);

/// @brief Pega o elemento anterior da lista (sem remover)
/// @param i Elemento que o elemento anterior será pego
/// @return Ponteiro para o elemento anterior ou NULL se estiver vazia
iterador getAnteriorLista(iterador i);

/// @brief Pega a quadrado elemento da lista
/// @param i Ponteiro para o elemento que a quadraserá pega
/// @return Um ponteiro para a quadra pega
quadra getQuadraLista(iterador i);

/// @brief Pega o tamanho da lista
/// @param l Ponteiro para a lista onde o tamanho será pego
/// @return Um inteiro com o tamanho da lista
int getTamanhoLista(lista l);

/// @brief Libera toda memória alocada da lista e seus elementos
/// @param l Ponteiro para a lista que será liberada
void liberarLista(lista l);

/// @brief Libera apenas os nós da lista (sem liberar o conteúdo)
/// @param l Ponteiro para a lista que os nós serão liberados
void liberarApenasNosLista(lista l);

#endif