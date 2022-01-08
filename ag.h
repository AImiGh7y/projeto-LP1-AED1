//
// Created by Nuno on 04/01/2022.
//

#ifndef PROJETOLP_AED_AG_H
#define PROJETOLP_AED_AG_H

#include "viagem.h"

/*
 * ● P: tamanho da população inicial (número par) e para cada geração (exemplo P=20)
    ● Q: probabilidade de mutação dum gene (exemplo Q=0.01)
    ● E: número de indivíduos que passam por elitismo diretamente para a próxima
    geração (número par E, com E < P; exemplo E=2)
    ● G: número de gerações a serem executadas pelo AG (exemplo AG=50)
    ● N: número de cidades que representam o número de genes de cada indivíduo ou
    cromossoma (exemplo N=6)
 *
 *
 *
 * */

typedef struct geracao {
    VIAGEM **progenitores;
    VIAGEM **herdeiros;
    struct geracao *proxima;
} GERACAO;

typedef struct ag {
    int P;  //tamanho da população inicial
    float Q;    //probabilidade de mutação dum gene
    int E;  //número de indivíduos que passam por elitismo diretamente para a próxima geração
    int G;  //número de gerações
    int N;  //número de cidades
    GERACAO *primeira_geracao;
} AG;

AG *ag_criar(int P, float Q, int E, int G, int N);
GERACAO *geracao_criar();

void ag_inserir_geracao_cabeca(AG *ag, GERACAO *nova);
void ag_inserir_geracao_cauda(AG *ag, GERACAO *nova);

GERACAO *ag_pesquisar_geracao_id(AG *ag, int iteracao);

GERACAO *ag_criar_geracao_aleatoria(AG *ag, CIDADE **cidades);
GERACAO *ag_criar_proxima_geracao(AG *ag);

float calcular_distancia(VIAGEM *viagem);
float calcular_aptidao(VIAGEM *viagem);
int selecao_por_aptidao(AG *ag, GERACAO *geracao);
VIAGEM *cruzamento_viagens(VIAGEM *p1, VIAGEM *p2);
VIAGEM *ag_melhor_aptidao(AG *ag, GERACAO *g);

#endif //PROJETOLP_AED_AG_H
