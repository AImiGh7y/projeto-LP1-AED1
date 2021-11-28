//
// Created by Nuno on 28/11/2021.
//

#include "poi.h"
#include <stdlib.h>
#include <string.h>

POI *criar_poi(char *nome, char *morada)
{
    POI *poi = malloc(sizeof(POI));
    strcpy(poi->nome, nome);
    strcpy(poi->morada, morada);
    poi->proximo = NULL;
    return poi;
}

void inserir_poi(POIS *pois, POI *poi)
{
    poi->proximo = pois->primeiro;
    pois->primeiro = poi;
}

POI *pesquisar_nome_poi(POIS *pois, char *nome) {
    POI *it = pois->primeiro;
    while (it != NULL) {
        if(strcmp(it->nome, nome) == 0)
            return it;
        it = it->proximo;
    }
    return NULL;  // nao encontrei
}

void remover_poi(POIS *pois, POI *poi)
{
    POI *it = pois->primeiro;
    POI *anterior = NULL;
    while(it != NULL) {
        if(it == poi) {
            if(anterior == NULL)
                pois->primeiro = poi->proximo;
            else
                anterior->proximo = it->proximo;
            free(it);
            break;
        }
        anterior = it;
        it = it->proximo;
    }
}

