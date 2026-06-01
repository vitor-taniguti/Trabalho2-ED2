#ifndef TXT_H
#define TXT_H

#include <stdio.h>
#include <stdlib.h>
#include "quadra.h"

/*
Módulo responsável por gerenciar a criação e escrita dos arquivos txt.
Os comentários feitos estão no padrão que o trabalho solicitou.
*/

typedef FILE* arquivo;

/// @brief Abre um arquivo de texto para gravação
/// @param txt Ponteiro duplo para o endereço do arquivo
/// @param caminhoTxt Ponteiro para o caminho onde será salvo o arquivo de texto
void abrirArquivoTxt(arquivo* txt, char* caminhoTxt);

/// @brief Printa a linha de comando lida no qry
/// @param txt Arquivo de texto onde a linha de comando será printada
/// @param linhaComando A linha de comando do qry
void printarLinhaComandoTxt(arquivo txt, char* linhaComando);

#endif