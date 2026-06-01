#ifndef VIA_H
#define VIA_H

#include <stdio.h>
#include "hashfile.h"
#include "quadra.h"
#include "grafo.h"

/*
Módulo responsável por gerenciar a criação e escrita dos arquivos via.
A leitura do arquivo cria e insere vértices e arestas com seus respectivos atributos no grafo do mapa viário.
Esse módulo é responsável pela criação das ruas da cidade (abstração).
*/

typedef FILE* arquivo;

/// @brief Abre o arquivo para leitura
/// @param =via Ponteiro para o arquivo que será aberto
/// @param caminhoVia Caminho para o arquivo que será aberto
void abrirArquivoVia(arquivo *via, char *caminhoVia);

/// @brief Lê e processa as linhas de um arquivop de entrada
/// @param via Ponteiro para o arquivo de entrada
/// @param quadras Hash onde as quadras serão inseridas
/// @param g Grafo do mapa viário
void lerArquivoVia(arquivo via, hash quadras, grafo g);

#endif