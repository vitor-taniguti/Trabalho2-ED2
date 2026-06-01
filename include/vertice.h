#ifndef VERTICE_H
#define VERTICE_H

typedef void *vertice;

/// @brief Cria um vértice com os atributos especificados
/// @param id Id do vértice
/// @param x Coordenada X do vértice
/// @param y Coordenada Y do vértice
/// @return O vértice criado com os atriutos especificados
vertice criarVertice(char* id, double x, double y);

/// @brief Pega o id do vértice
/// @param v Ponteiro para o vértice
/// @return O id do vértice
char* getIdVertice(vertice v);

/// @brief Pega a coordenada X do vértice
/// @param v Ponteiro para o vértice
/// @return A coordenada X do vértice
double getXVertice(vertice v);

/// @brief Pega a coordenada Y do vértice
/// @param v Ponteiro para o vértice
/// @return A coordenada Y do vértice
double getYVertice(vertice v);

/// @brief Define a coordenada X do vértice
/// @param v Ponteiro para o vértice
/// @param x Coordenada X do vértice
void setXVertice(vertice v, double x);

/// @brief Define a coordenada Y do vértice
/// @param v Ponteiro para o vértice
/// @param y Coordenada Y do vértice
void setYVertice(vertice v, double y);

#endif