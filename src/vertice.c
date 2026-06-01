#include "vertice.h"
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* id;
    double x, y;
} Vertice;

vertice criarVertice(char* id, double x, double y){
    Vertice* v = (Vertice*) malloc(sizeof(Vertice));

    v->id = malloc((strlen(id)+1));
    if (v->id == NULL) {
        printf("Erro ao alocar memória para o id do vértice!\n");
        exit(1);
    }
    strcpy(v->id, id);

    v->x = x;
    v->y = y;

    return v;
}

char* getIdVertice(vertice v){
    return ((Vertice*)v)->id;
}

double getXVertice(vertice v){
    return ((Vertice*)v)->x;
}

double getYVertice(vertice v){
    return ((Vertice*)v)->y;
}

void setXVertice(vertice v, double x){
    ((Vertice*)v)->x = x;
}

void setYVertice(vertice v, double y){
    ((Vertice*)v)->y = y;
}
