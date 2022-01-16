//
// Created by Nuno on 28/11/2021.
//

#ifndef PROJETOLP_AED_POI_H
#define PROJETOLP_AED_POI_H

typedef struct poi {
    char nome[64];
    char morada[256];
    struct poi *proximo;
} POI;

typedef struct pois {
    POI *primeiro;
} POIS;

POI *criar_poi(char *nome, char *morada);
void inserir_poi(POIS *pois, POI *poi);
POI *pesquisar_nome_poi(POIS *pois, char *nome);
void remover_poi(POIS *pois, POI *poi);

void editar_nome_poi(POI *poi, char *novo_nome);

#endif //PROJETOLP_AED_POI_H
