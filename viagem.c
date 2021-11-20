//
// Created by Nuno on 20/11/2021.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "viagem.h"

CIDADE *criar_array_cidades(int tamanho) {
    return calloc(tamanho, sizeof(CIDADE));
}

CIDADE *redimensionar_array_cidades(CIDADE *cidades, int novo_tamanho) {
    return realloc(cidades, novo_tamanho*sizeof(CIDADE));
}

VIAGEM *criar_viagem() {
    VIAGEM *viagem = malloc(sizeof(VIAGEM));
    viagem->cidades = NULL;
    viagem->num_cidades = 0;
    return viagem;
}

void adicionar_cidade_a_viagem(VIAGEM *viagem, char *nome, char *descricao) {
    viagem->cidades = redimensionar_array_cidades(viagem->cidades, viagem->num_cidades+1);
    strcpy(viagem->cidades[viagem->num_cidades].nome, nome);
    strcpy(viagem->cidades[viagem->num_cidades].descricao, descricao);
    viagem->num_cidades++;
}

void remover_cidade_a_viagem(VIAGEM *viagem, char *nome) {
    // procurar pela cidade com "nome"
    int posicao = -1;
    for(int i = 0; i < viagem->num_cidades; i++) {
        if(strcmp(viagem->cidades[i].nome, nome) == 0) {
            posicao = i;
            break;
        }
    }
    if(posicao < 0) {
        printf("Erro: cidade %s nao encontrada\n", nome);
        return;
    }
    // puxar tudo o que seja > posicao para a esquerda
    for(int i = posicao+1; i < viagem->num_cidades; i++) {
        viagem->cidades[i-1] = viagem->cidades[i];    // TODO
    }
    // redimensionar
    viagem->cidades = redimensionar_array_cidades(viagem->cidades, viagem->num_cidades-1);
    viagem->num_cidades--;
}

int comparar_viagem(VIAGEM *a, VIAGEM *b)
{
    if(a->num_cidades != b->num_cidades)
        return 0;
    for(int i = 0; i < a->num_cidades; i++)
        if(comparar_cidades(&a->cidades[i], &b->cidades[i]) == 0)
            return 0;
    return 1;
}

void imprimir_viagem(VIAGEM *viagem)
{
    for(int i = 0; i < viagem->num_cidades; i++)
        imprimir_cidade(&viagem->cidades[i]);
}
