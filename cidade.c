//
// Created by Nuno on 20/11/2021.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"

CIDADE *criar_cidade(char *nome, char *descricao, float lat, float lon)
{
    CIDADE *cidade = malloc(sizeof(CIDADE));
    strcpy(cidade->nome, nome);
    strcpy(cidade->descricao, descricao);
    cidade->lat = lat;
    cidade->lon = lon;
    return cidade;
}

int comparar_cidades(CIDADE *a, CIDADE *b) {
    if(strcmp(a->nome, b->nome) == 0 && strcmp(a->descricao, b->descricao) == 0)
        return 1;
    else
        return 0;
}

void imprimir_cidade(CIDADE *cidade) {
    printf("%s\n", cidade->nome);
}
