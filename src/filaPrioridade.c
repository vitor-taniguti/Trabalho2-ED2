#include "filaPrioridade.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct NoFila {
    vertice v;               
    double prioridade;        
    struct NoFila* proximo; 
} NoFila;

typedef struct {
    NoFila* primeiro; 
} FilaPrioridade;

filaPrioridade criarFilaPrioridade() {
    FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    f->primeiro = NULL;
    return f;
}

void inserirFilaPrioridade(filaPrioridade f, vertice v, double prioridade) {
    FilaPrioridade* fila = (FilaPrioridade*) f;
    NoFila* novoNo = (NoFila*) malloc(sizeof(NoFila));

    novoNo->v = v;
    novoNo->prioridade = prioridade;
    novoNo->proximo = NULL;

    if (fila->primeiro == NULL || fila->primeiro->prioridade > prioridade) {
        novoNo->proximo = fila->primeiro;
        fila->primeiro = novoNo;
    } else {
        NoFila* atual = fila->primeiro;

        while (atual->proximo != NULL && atual->proximo->prioridade <= prioridade) {
            atual = atual->proximo;
        }

        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

vertice extrairMinimoFilaPrioridade(filaPrioridade f) {
    FilaPrioridade* fila = (FilaPrioridade*) f;

    if (fila->primeiro == NULL) return NULL; 

    NoFila* noMinimo = fila->primeiro;
    vertice vMinimo = noMinimo->v;

    fila->primeiro = noMinimo->proximo;
    free(noMinimo);

    return vMinimo;
}

int estaVaziaFilaPrioridade(filaPrioridade f) {
    FilaPrioridade* fila = (FilaPrioridade*) f;
    return fila->primeiro == NULL;
}

void liberarFilaPrioridade(filaPrioridade f) {
    FilaPrioridade* fila = (FilaPrioridade*) f;
    NoFila* atual = fila->primeiro;

    while (atual != NULL) {
        NoFila* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(fila);
}