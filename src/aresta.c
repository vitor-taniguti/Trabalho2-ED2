#include "aresta.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct{
    vertice v1, v2;
    char *ldir, *lesq, *nome; 
    double cmp, vm;
} Aresta;

aresta criarAresta(vertice v1, vertice v2, char* ldir, char* lesq, double cmp, double vm, char* nome){
    Aresta* a = malloc(sizeof(Aresta));

    a->v1 = v1;
    a->v2 = v2;

    a->ldir = malloc(strlen(ldir)+1);
    if (a->ldir == NULL){
        printf("Erro ao alocar memória para o lado direito da aresta!\n");
        exit(1);
    }
    strcpy(a->ldir, ldir);

    a->lesq = malloc(strlen(lesq)+1);
    if (a->lesq == NULL){
        printf("Erro ao alocar memória para o lado esquerdo da aresta!\n");
        exit(1);
    }
    strcpy(a->lesq, lesq);

    a->cmp = cmp;
    a->vm = vm;

    a->nome = malloc(strlen(nome)+1);
    if (a->nome == NULL){
        printf("Erro ao alocar memória para o nome da aresta!\n");
        exit(1);
    }
    strcpy(a->nome, nome);

    return a;
}

vertice getV1Aresta(aresta a){
    return ((Aresta*)a)->v1;
}

vertice getV2Aresta(aresta a){
    return ((Aresta*)a)->v2;
}

char* getLdirAresta(aresta a){
    return ((Aresta*)a)->ldir;
}

char* getLesqAresta(aresta a){
    return ((Aresta*)a)->lesq;
}

double getCmpAresta(aresta a){
    return ((Aresta*)a)->cmp;
}

double getVmAresta(aresta a){
    return ((Aresta*)a)->vm;
}

char* getNomeAresta(aresta a){
    return ((Aresta*)a)->nome;
}

void setLdirAresta(aresta a, char* ldir){
    Aresta* aux = (Aresta*) a;
    realloc(aux->ldir, strlen(ldir)+1);
    strcpy(aux->ldir, ldir);
}

void setLesqAresta(aresta a, char* lesq){
    Aresta* aux = (Aresta*) a;
    realloc(aux->ldir, strlen(lesq)+1);
    strcpy(aux->lesq, lesq);
}

void setCmpAresta(aresta a, double cmp){
    Aresta* aux = (Aresta*) a;
    aux->cmp = cmp;
}

void setVmAresta(aresta a, double vm){
    Aresta* aux = (Aresta*) a;
    aux->vm = vm;
}