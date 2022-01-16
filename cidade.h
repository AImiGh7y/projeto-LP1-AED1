//
// Created by Nuno on 20/11/2021.
//

#ifndef PROJETOLP_AED_CIDADE_H
#define PROJETOLP_AED_CIDADE_H

#include "poi.h"

typedef struct cidade {
    char nome[128];
    char descricao[1024];
    POIS pois;
    float lat, lon;
} CIDADE;

CIDADE *criar_cidade(char *nome, char *descricao, float lat, float lon);

void mudar_nome_cidade(CIDADE *cidade, char *novo_nome);

int comparar_cidades(CIDADE *a, CIDADE *b);

void imprimir_cidade(CIDADE *cidade);

#endif //PROJETOLP_AED_CIDADE_H
