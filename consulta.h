//
// Created by Nuno on 28/11/2021.
//

#ifndef PROJETOLP_AED_CONSULTA_H
#define PROJETOLP_AED_CONSULTA_H

#include "viagem.h"
#include "clientes.h"

VIAGEM *viagem_que_passou(CLIENTES *clientes, char *nome_cidade);
VIAGEM *viagem_visitou_poi(CLIENTES *clientes, char *nome_poi);

#endif //PROJETOLP_AED_CONSULTA_H
