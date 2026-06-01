#include "registrador.h"

#define QUANTIDADE_REGISTRADORES 11

typedef struct{
    double x;
    double y;
    int ativo;
} Registrador;

registrador* criarRegistradores(){
    Registrador* registradores = (Registrador*) malloc(QUANTIDADE_REGISTRADORES * sizeof(Registrador));

    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++){
        registradores[i].x = 0.0;
        registradores[i].y = 0.0;
        registradores[i].ativo = 0;
    }

    return registradores;
}

void salvarPosicaoRegistrador(int indice, double x, double y){
    if (indice < 0 || indice >= QUANTIDADE_REGISTRADORES){
        printf("Índice de registrador inválido.\n");
        return;
    }

    Registrador* registradores = (Registrador*) criarRegistradores();

    registradores[indice].x = x;
    registradores[indice].y = y;
    registradores[indice].ativo = 1;
}

int getPosicaoRegistrador(int indice, double* x, double* y){
    if (indice < 0 || indice >= QUANTIDADE_REGISTRADORES){
        printf("Índice de registrador inválido.\n");
        return 0;
    }

    Registrador* registradores = (Registrador*) criarRegistradores();

    if (registradores[indice].ativo){
        *x = registradores[indice].x;
        *y = registradores[indice].y;
        return 1;
    } else{
        printf("Registrador não ativo.\n");
        return 0;
    }
}

void liberarRegistradores(registrador* registradores){
    free(registradores);
}