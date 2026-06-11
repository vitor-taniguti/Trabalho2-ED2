#include "qry.h"
#include "quadra.h"
#include "hashfile.h"
#include "grafo.h"
#include "registrador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void abrirArquivoQry(arquivo *qry, char *caminhoQry){
    *qry = fopen(caminhoQry, "r");
    if(*qry == NULL){
        printf("Erro na abertura do arquivo qry!\n");
        exit(1);
    }
}

void o(registrador* registradores, int numeroRegistrador, char* cep, char face, int numero){
    registrador r = getRegistradorPorIndice(numeroRegistrador, registradores);
    salvarPosicaoRegistrador(r, cep, face, numero);
}

static void processarLinha(char* linha, char* comando, hash quadras, grafo mapaViario, arquivo txt, arquivo svg, registrador* registradores){
    char cpf[15] = {0}, nome[50] = {0}, sobrenome[50] = {0}, sexo = ' ', nascimento[11] = {0};
    char cep[10] = {0}, complemento[10] = {0}, lado = ' ', tipo[2] = {0};
    int numeroRegistrador = 0, numero = 0;

    printarLinhaComandoTxt(txt, linha);
    
    if (strcmp(comando, "@o?") == 0){
        sscanf(linha, "%3s %d %s %c %d", comando, &numeroRegistrador, cep, &lado, &numero);
        o(registradores, numeroRegistrador, cep, lado, numero);
    } else printf("Comando do qry inválido!\n");
}

void lerArquivoQry(arquivo qry, arquivo txt, arquivo svg, hash quadras, grafo mapaViario, registrador* registradores){
    if (qry == NULL){
        printf("O arquivo qry não foi aberto!\n");
        exit(1);
    }

    char linha[256], comando[6];

    while (fgets(linha, sizeof(linha), qry)){
        int i = 0;

        while (linha[i] != ' ' && linha[i] != '\n' && linha[i] != '\0'){
            comando[i] = linha[i];
            i++;
        }

        comando[i] = '\0';

        processarLinha(linha, comando, quadras, mapaViario, txt, svg, registradores);
    }
}