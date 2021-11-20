//
// Created by Nuno on 20/11/2021.
//

#ifndef PROJETOLP_AED_CIDADE_H
#define PROJETOLP_AED_CIDADE_H

typedef struct cidade {
    char nome[128];
    char descricao[1024];
} CIDADE;

int comparar_cidades(CIDADE *a, CIDADE *b);

void imprimir_cidade(CIDADE *cidade);

#endif //PROJETOLP_AED_CIDADE_H
