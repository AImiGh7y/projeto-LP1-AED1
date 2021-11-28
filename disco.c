//
// Created by Nuno on 28/11/2021.
//

#include "disco.h"
#include "clientes.h"
#include <stdio.h>

void escrever_ficheiros_txt(CLIENTES *clientes)
{
    FILE *f = fopen("clientes.txt", "w");

    CLIENTE *it = clientes->primeiro;
    while(it != NULL) {
        fprintf(f, "%s,%d,%d,%d\n", it->nome, it->NIF, it->contacto, it->num_viagens);
        it = it->proximo;
    }

    fclose(f);
}

CLIENTES *ler_ficheiros_txt()
{
    FILE *f = fopen("clientes.txt", "r");

    CLIENTES *clientes = criar_clientes();
    while(!feof(f)) {
        char nome[128];
        int NIF;
        int contacto;
        int num_viagens;
        fscanf(f, "%s,%d,%d,%d\n", nome, &NIF, &contacto, &num_viagens);
        CLIENTE *cliente = criar_cliente(nome, NIF, contacto);
        inserir_cabeca(clientes, cliente);
    }

    fclose(f);
    return clientes;
}
