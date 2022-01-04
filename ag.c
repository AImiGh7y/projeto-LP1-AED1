//
// Created by Nuno on 04/01/2022.
//

#include <stdlib.h>
#include <math.h>
#include "ag.h"

AG *ag_criar(int P, float Q, int E, int G, int N)
{
    AG *ag = malloc(sizeof(AG));
    ag->primeira_geracao = NULL;
    ag->P = P;
    ag->Q = Q;
    ag->E = E;
    ag->G = G;
    ag->N = N;
    return ag;
}

GERACAO *ag_criar_geracao_aleatoria(AG *ag, CIDADE **cidades)
{
    GERACAO *geracao = malloc(sizeof(GERACAO));
    geracao->progenitores = calloc(sizeof(VIAGEM*), ag->P);
    geracao->herdeiros = calloc(sizeof(VIAGEM*), ag->E);

    for(int i = 0; i < ag->P; i++) {
        geracao->progenitores[i] = malloc(sizeof(VIAGEM));

        // vamos adicionar N cidades
        int j = 0;
        while(j < ag->N) {
            // escolher aleatoriamente cidade
            int k = rand() % ag->N;
            CIDADE *c = cidades[k];
            // ver se ja nao foi escolhida
            if(!viagem_tem_cidade(geracao->progenitores[i], c)) {
                adicionar_cidade_a_viagem(geracao->progenitores[i], c);
                j++;
            }
        }
    }

    geracao->proximo = NULL;
    return geracao;
}

void ag_inserir_geracao_cabeca(AG *ag, GERACAO *nova)
{
    nova->proximo = ag->primeira_geracao;
    ag->primeira_geracao = nova;
}

void ag_inserir_geracao_cauda(AG *ag, GERACAO *nova) {
    if(ag->primeira_geracao == NULL) {
        ag->primeira_geracao = nova;
        return;
    }
    GERACAO *it = ag->primeira_geracao;
    while (it->proximo != NULL) {
        it = it->proximo;
    }
    it->proximo = nova;
}

GERACAO *ag_pesquisar_geracao_id(AG *ag, int iteracao)
{
    GERACAO *it = ag->primeira_geracao;
    for(int i = 0; i < iteracao; i++)
        it = it->proximo;
    return it;
}

float calcular_aptidao(VIAGEM *viagem)
{
    float result = 0;
    CIDADE *anterior = NULL;
    for(int i = 0; i < viagem->num_cidades; i++) {
        CIDADE *cidade = viagem->cidades[i];
        if(anterior != NULL) {
            result += sqrt(pow(cidade->lat-anterior->lat, 2) + pow(cidade->lon-anterior->lon, 2));
        }
        anterior = cidade;
    }
    return result;
}
