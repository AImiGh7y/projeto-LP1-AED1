//
// Created by Nuno on 14/11/2021.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "clientes.h"

CLIENTES *criar_clientes()
{
    CLIENTES *clientes = malloc(sizeof(CLIENTES));
    clientes->primeiro = NULL;
    return clientes;
}

CLIENTE *criar_cliente(char *nome, int NIF, int contacto) {
    CLIENTE *cliente = malloc(sizeof(CLIENTE));
    strcpy(cliente->nome, nome);
    cliente->NIF = NIF;
    cliente->contacto = contacto;
    cliente->proximo = NULL;
}

void inserir_cabeca(CLIENTES *clientes, CLIENTE *cliente)
{
    cliente->proximo = clientes->primeiro;
    clientes->primeiro = cliente;
}

void inserir_cauda(CLIENTES *clientes, CLIENTE *cliente)
{
    if(clientes->primeiro == NULL) {
        clientes->primeiro = cliente;
        return;
    }
    CLIENTE *it = clientes->primeiro;
    while(it->proximo != NULL) {
        it = it->proximo;
    }
    it->proximo = cliente;
}

void inserir_ordenado_NIF(CLIENTES *clientes, CLIENTE *cliente)
{
}

void inserir_ordenado_nome(CLIENTES *clientes, CLIENTE *cliente)
{
}

CLIENTE *pesquisar_NIF(CLIENTES *clientes, int NIF)
{
    CLIENTE *it = clientes->primeiro;
    while(it != NULL) {
        // ...

        it = it->proximo;
    }
    // nao encontrei
    return NULL;
}

CLIENTE *pesquisar_nome(CLIENTES *clientes, char *nome) {
    CLIENTE *it = clientes->primeiro;
    while (it != NULL) {
        // ...

        it = it->proximo;
    }
    // nao encontrei
    return NULL;
}

void remover_cliente(CLIENTES *clientes, CLIENTE *cliente)
{
    CLIENTE *anterior = NULL;
    CLIENTE *it = clientes->primeiro;
    while(it != NULL) {
        if(it == cliente) {
            if(anterior == NULL)
                clientes->primeiro = it->proximo;
            else
                anterior->proximo = it->proximo;
            free(it);
            break;
        }

        // incremento
        anterior = it;
        it = it->proximo;
    }
}

void imprimir_clientes(CLIENTES *clientes)
{
    CLIENTE *it = clientes->primeiro;
    while (it != NULL) {
        printf("%s\n", it->nome);
        it = it->proximo;
    }
}
