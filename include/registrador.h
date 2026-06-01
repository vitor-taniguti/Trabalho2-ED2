#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef void* registrador;

registrador* criarRegistradores();

registrador getRegistradorPorIndice(int indice);

void salvarPosicaoRegistrador(int indice, double x, double y);

int getPosicaoRegistrador(int indice, double* x, double* y);

void liberarRegistradores(registrador* registradores);

#endif