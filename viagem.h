//
// Created by Nuno on 20/11/2021.
//

#ifndef PROJETOLP_AED_VIAGEM_H
#define PROJETOLP_AED_VIAGEM_H

#include "cidade.h"

typedef struct viagem {
    CIDADE *cidades;
    int num_cidades;
} VIAGEM;

VIAGEM *criar_viagem();
void adicionar_cidade_a_viagem(VIAGEM *viagem, char *nome, char *descricao);
void remover_cidade_a_viagem(VIAGEM *viagem, char *nome);

int comparar_viagem(VIAGEM *a, VIAGEM *b);

void imprimir_viagem(VIAGEM *viagem);

#endif //PROJETOLP_AED_VIAGEM_H
