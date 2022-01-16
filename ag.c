//
// Created by Nuno on 04/01/2022.
//

#include <stdlib.h>
#include <stdio.h>
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
    geracao->herdeiros = NULL;

    for(int i = 0; i < ag->P; i++) {
        geracao->progenitores[i] = criar_viagem();

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

    geracao->proxima = NULL;
    ag->primeira_geracao = geracao;
    return geracao;
}

void ag_inserir_geracao_cabeca(AG *ag, GERACAO *nova)
{
    nova->proxima = ag->primeira_geracao;
    ag->primeira_geracao = nova;
}

void ag_inserir_geracao_cauda(AG *ag, GERACAO *nova) {
    if(ag->primeira_geracao == NULL) {
        ag->primeira_geracao = nova;
        return;
    }
    GERACAO *it = ag->primeira_geracao;
    while (it->proxima != NULL) {
        it = it->proxima;
    }
    it->proxima = nova;
}

GERACAO *ag_pesquisar_geracao_id(AG *ag, int iteracao)
{
    GERACAO *it = ag->primeira_geracao;
    for(int i = 0; i < iteracao; i++)
        it = it->proxima;
    return it;
}

float calcular_aptidao(VIAGEM *viagem)
{
    return 1/calcular_distancia(viagem);
}

float calcular_distancia(VIAGEM *viagem)
{
    float result = 0;
    for(int i = 0; i < viagem->num_cidades; i++) {
        CIDADE *ci = viagem->cidades[i];
        CIDADE *cj;
        if(i+1 >= viagem->num_cidades)
            cj = viagem->cidades[0];
        else
            cj = viagem->cidades[i+1];
        result += sqrt(pow(ci->lat - cj->lat, 2) + pow(ci->lon - cj->lon, 2));
    }
    return result;
}

int selecao_por_aptidao(AG *ag, GERACAO *geracao)
{
    // calcular soma apitadoes
    float sum_A = 0;
    for(int i = 0; i < ag->P; i++)
        sum_A += calcular_aptidao(geracao->progenitores[i]);

    // escolher aleatoriamente
    for(int i = 0; i < ag->P; i++) {
        float P = calcular_aptidao(geracao->progenitores[i]) / sum_A;
        float rand_01 = rand() / (float) RAND_MAX;
        if(rand_01 < P) {
            return i;
        }
    }
    return ag->N-1;
}

VIAGEM *cruzamento_viagens(VIAGEM *p1, VIAGEM *p2)
{
    VIAGEM *filho = criar_viagem();
    filho->num_cidades = p1->num_cidades;
    filho->cidades = calloc(p1->num_cidades, sizeof(CIDADE));

    // sub-conjunto [i1,i2] de um progenitor (p1)
    int i1 = rand() % p1->num_cidades;
    int i2 = i1 + (rand() % p1->num_cidades);
    for(int j = i1; j <= i2; j++)
        filho->cidades[j] = p1->cidades[j];
    // o resto e' preenchido pelo outro progenitor (p2)
    int j = 0;
    if(j == i1)
        j = i2+1;
    for(int k = 0; k < p2->num_cidades; k++) {
        // ver se cidade p2->cidades[k] ja pertence a filho no sub-conjunto
        int ja_existe = 0;
        for(int l = i1; l <= i2; l++)
            if(filho->cidades[l] == p2->cidades[k])
                ja_existe = 1;
        if(!ja_existe) {
            // escolher a cidade
            filho->cidades[j] = p2->cidades[k];
            j++;
            if(j == i1)
                j = i2+1;
        }
    }
    return filho;
}

GERACAO *ag_criar_proxima_geracao(AG *ag)
{
    GERACAO *ultima = ag->primeira_geracao;
    while(ultima->proxima != NULL)
        ultima = ultima->proxima;
    ultima->herdeiros = calloc(ag->P, sizeof(VIAGEM*));

    // cruzamentos
    for(int i = 0; i < ag->P - ag->E; i += 2) {
        int p1 = selecao_por_aptidao(ag, ultima);
        int p2 = selecao_por_aptidao(ag, ultima);
        ultima->herdeiros[i] = cruzamento_viagens(ultima->progenitores[p1], ultima->progenitores[p2]);
        if(i+1 < ag->P)
            ultima->herdeiros[i+1] = cruzamento_viagens(ultima->progenitores[p2], ultima->progenitores[p1]);
    }

    // elitismo
    for(int i = ag->P - ag->E; i < ag->P; i++) {
        int p = selecao_por_aptidao(ag, ultima);
        ultima->herdeiros[i] = ultima->progenitores[p];
    }

    // mutacoes
    for(int i = 0; i < ag->P; i++) {
        for(int j = 0; j < ag->N; j++) {
            if(rand() / (float) RAND_MAX < ag->Q) {
                // mutacao: escolhe outra cidade aleatoria e troca
                int j2 = rand() % ag->N;
                CIDADE *temp = ultima->herdeiros[i]->cidades[j];
                ultima->herdeiros[i]->cidades[j] = ultima->herdeiros[i]->cidades[j2];
                ultima->herdeiros[i]->cidades[j2] = temp;
            }
        }
    }

    // proxima geracao
    GERACAO *nova = malloc(sizeof(GERACAO));
    nova->progenitores = ultima->herdeiros;
    nova->herdeiros = NULL;
    nova->proxima = NULL;
    ultima->proxima = nova;
    return ultima;
}

VIAGEM *ag_melhor_aptidao(AG *ag, GERACAO *g)
{
    float melhor_aptidao = 0;
    VIAGEM *melhor_viagem = NULL;
    for(int i = 0; i < ag->P; i++) {
        float A = calcular_aptidao(g->progenitores[i]);
        if(A > melhor_aptidao) {
            melhor_aptidao = A;
            melhor_viagem = g->progenitores[i];
        }
    }
    return melhor_viagem;
}