#include "via.h"
#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void abrirArquivoVia(arquivo* via, char* caminhoVia){
    *via = fopen(caminhoVia, "r");
    if (*via == NULL){
        printf("Falha na abertura do arquivo!");
        exit(1);
    }
}

static void processarLinha(char* linha, char* comando, grafo mapaViario, arquivo txt, arquivo svg){
    char id1[10] = {0}, id2[10] = {0}, ldir[50] = {0}, lesq[50] = {0}, nome[50] = {0};
    double x = 0.0, y = 0.0, cmp = 0.0, vm = 0.0;
    char tipo[20] = {0};

    printarLinhaComandoTxt(txt, linha);
    
    if (strcmp(comando, "v") == 0){
        sscanf(linha, "%1s %10s %lf %lf", comando, id1, &x, &y);

        vertice v = criarVertice(id1, x, y);
        inserirVerticeGrafo(mapaViario, v);
    } else if (strcmp(comando, "e") == 0){
        sscanf(linha, "%1s %10s %50s %50s %lf %lf %50s", tipo, id1, id2, ldir, lesq, &cmp, &vm, nome);

        vertice v1 = buscarVerticeGrafo(mapaViario, id1);
        vertice v2 = buscarVerticeGrafo(mapaViario, id2);

        if (v1 == NULL){
            printf("Vértice %s não encontrado para criar a aresta!\n", id1);
            return;
        }
        if (v2 == NULL){
            printf("Vértice %s não encontrado para criar a aresta!\n", id2);
            return;
        }

        aresta a = criarAresta(v1, v2, ldir, lesq, cmp, vm, nome);
        inserirArestaGrafo(mapaViario, a);
    } else printf("Comando do via inválido!\n");
}

void lerArquivoVia(arquivo via, arquivo txt, arquivo svg, grafo mapaViario){
    if (via == NULL){
        printf("O arquivo via não foi aberto!\n");
        exit(1);
    }

    char linha[256], comando[6];
    int quantidadeVertices = 0;

    sscanf(via, "%d", &quantidadeVertices);
    setQuantidadeVerticesGrafo(mapaViario, quantidadeVertices);

    while (fgets(linha, sizeof(linha), via)){
        int i = 0;

        while (linha[i] != ' ' && linha[i] != '\n' && linha[i] != '\0'){
            comando[i] = linha[i];
            i++;
        }

        comando[i] = '\0';

        processarLinha(linha, comando, mapaViario, txt, svg);
    }
}