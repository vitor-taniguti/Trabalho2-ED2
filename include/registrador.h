#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef void* registrador;

registrador* criarRegistradores();

registrador getRegistradorPorIndice(int indice, registrador* registradores);

void salvarPosicaoRegistrador(registrador r, char* cep, char* numero, char* face);

int getPosicaoRegistrador(int indice, double* x, double* y);

void liberarRegistradores(registrador* registradores);

#endif