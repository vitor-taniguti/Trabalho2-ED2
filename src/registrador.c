#include "registrador.h"
#include <stdlib.h>
#include <string.h>

#define QUANTIDADE_REGISTRADORES 11

typedef struct{
    char* cep;
    char* face;
    char* numero;
    int ativo;
} Registrador;

registrador* criarRegistradores(){
    Registrador* registradores = (Registrador*) malloc(QUANTIDADE_REGISTRADORES * sizeof(Registrador));

    for (int i = 0; i < QUANTIDADE_REGISTRADORES; i++){
        registradores[i].cep = NULL;
        registradores[i].face = NULL;
        registradores[i].numero = NULL;
        registradores[i].ativo = 0;
    }

    return registradores;
}

registrador getRegistradorPorIndice(int indice, registrador* registradores){
    Registrador** rs = registradores;
    return rs[indice];
}

void salvarPosicaoRegistrador(registrador r, char* cep, char* numero, char* face){
    Registrador* registrador = r;

    registrador->cep = malloc(strlen(cep)+1);
    if (registrador->cep == NULL){
        printf("Falha ao alocar memória para o cep no registrador!\n");
        return;
    }
    strcpy(registrador->cep, cep);

    registrador->face = malloc(strlen(face)+1);
    if (registrador->face == NULL){
        printf("Falha ao alocar memória para a face no registrador!\n");
        return;
    }
    strcpy(registrador->face, face);

    registrador->numero = malloc(strlen(numero)+1);
    if (registrador->numero == NULL){
        printf("Falha ao alocar memória para o número no registrador!\n");
        return;
    }
    strcpy(registrador->numero, numero);

    registrador->ativo = 1;
}

int getPosicaoRegistrador(registrador r, char* cep, char* face, char* numero){
    Registrador* registrador = r;

    if (registrador->ativo){
        cep = malloc(strlen(registrador->cep)+1);
        if (cep == NULL){
            printf("Falha ao alocar memória para o cep a ser pego do registrador!\n");
            return;
        }
        strcpy(cep, registrador->cep);

        face = malloc(strlen(registrador->face)+1);
        if (face == NULL){
            printf("Falha ao alocar memória para a face a ser pego do registrador!\n");
            return;
        }
        strcpy(face, registrador->face);

        numero = malloc(strlen(registrador->numero)+1);
        if (numero == NULL){
            printf("Falha ao alocar memória para o número a ser pego do registrador!\n");
            return;
        }
        strcpy(numero, registrador->numero);

        return 1;
    } else{
        printf("Registrador não ativo.\n");
        return 0;
    }
}

void liberarRegistradores(registrador* registradores){
    free(registradores);
}