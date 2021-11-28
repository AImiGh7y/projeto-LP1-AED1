//
// Created by Nuno on 28/11/2021.
//

#include "consulta.h"
#include <string.h>

VIAGEM *viagem_que_passou(CLIENTES *clientes, char *nome_cidade)
{
    CLIENTE *it = clientes->primeiro;
    while(it != NULL) {
        for(int i = 0; i < it->num_viagens; i++) {
            VIAGEM *viagem = &it->viagens[i];
            for(int j = 0; j < viagem->num_cidades; j++) {
                if(strcmp(viagem->cidades[j].nome, nome_cidade) == 0) {
                    return viagem;
                }
            }
        }
        it = it->proximo;
    }
    return NULL;
}

VIAGEM *viagem_visitou_poi(CLIENTES *clientes, char *nome_poi)
{
    CLIENTE *it = clientes->primeiro;
    while(it != NULL) {
        for(int i = 0; i < it->num_viagens; i++) {
            VIAGEM *viagem = &it->viagens[i];
            for(int j = 0; j < viagem->num_cidades; j++) {
                POI *poi_it = viagem->cidades[j].pois.primeiro;
                while(poi_it != NULL) {
                    if(strcmp(poi_it->nome, nome_poi) == 0) {
                        return viagem;
                    }
                    poi_it = poi_it->proximo;
                }
            }
        }
        it = it->proximo;
    }
    return NULL;
}