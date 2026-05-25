#ifndef VERTICE_H
#define VERTICE_H

typedef void *vertice;

void criarVertice(char* id, double x, double y);

char* getIdVertice(vertice v);

double getXVertice(vertice v);

double getYVertice(vertice v);

void setXVertice(vertice v, double x);

void setYVertice(vertice v, double y);

#endif