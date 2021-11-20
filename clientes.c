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
    cliente->viagens = NULL;
    cliente->num_viagens = 0;
    cliente->proximo = NULL;
    return cliente;
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
    if(clientes->primeiro == NULL) {
        clientes->primeiro = cliente;
        return;
    }
    if(cliente->NIF < clientes->primeiro->NIF) {
        cliente->proximo = clientes->primeiro;
        clientes->primeiro = cliente;
        return;
    }

    // encontrar o no anterior
    CLIENTE *it = clientes->primeiro;
    while(it->proximo != NULL && it->proximo->NIF < cliente->NIF) {
        it = it->proximo;
    }
    // colocar novo cliente depois do it
    cliente->proximo = it->proximo;
    it->proximo = cliente;
}

void inserir_ordenado_nome(CLIENTES *clientes, CLIENTE *cliente)
{
    if(clientes->primeiro == NULL) {
        clientes->primeiro = cliente;
        return;
    }
    if(strcmp(cliente->nome, clientes->primeiro->nome) < 0) {
        cliente->proximo = clientes->primeiro;
        clientes->primeiro = cliente;
        return;
    }
    // encontrar o no anterior
    CLIENTE *it = clientes->primeiro;
    while(it->proximo != NULL && strcmp(it->proximo->nome, cliente->nome) < 0) {
        it = it->proximo;
    }
    // colocar novo cliente depois do it
    cliente->proximo = it->proximo;
    it->proximo = cliente;
}

CLIENTE *pesquisar_NIF(CLIENTES *clientes, int NIF)
{
    CLIENTE *it = clientes->primeiro;
    while(it != NULL) {
        if(it->NIF == NIF)
            return it;
        it = it->proximo;
    }
    return NULL;  // nao encontrei
}

CLIENTE *pesquisar_nome(CLIENTES *clientes, char *nome) {
    CLIENTE *it = clientes->primeiro;
    while (it != NULL) {
        if(strcmp(it->nome, nome) == 0)
            return it;
        it = it->proximo;
    }
    return NULL;  // nao encontrei
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

VIAGEM *redimensionar_array_viagens(CLIENTE *cliente, int novo_tamanho) {
    return realloc(cliente->viagens, novo_tamanho*sizeof(VIAGEM));
}

VIAGEM *inserir_viagem_no_cliente(CLIENTE *cliente)
{
    cliente->viagens = redimensionar_array_viagens(cliente, cliente->num_viagens+1);
    cliente->num_viagens++;
    VIAGEM *nova = &cliente->viagens[cliente->num_viagens-1];
    nova->cidades = NULL;
    nova->num_cidades = 0;
    return nova;
}

void remover_viagem_no_cliente(CLIENTE *cliente, VIAGEM *viagem)
{
    // procurar pela cidade com "nome"
    int posicao = -1;
    for(int i = 0; i < cliente->num_viagens; i++) {
        if(comparar_viagem(&cliente->viagens[i], viagem) == 1) {
            posicao = i;
            break;
        }
    }
    if(posicao < 0) {
        printf("Erro: viagem nao encontrada\n");
        return;
    }
    // puxar tudo o que seja > posicao para a esquerda
    for(int i = posicao+1; i < cliente->num_viagens; i++) {
        cliente->viagens[i-1] = cliente->viagens[i];  // TODO
    }
    // redimensionar
    cliente->viagens = redimensionar_array_viagens(cliente, cliente->num_viagens-1);
    cliente->num_viagens--;
}

void imprimir_clientes(CLIENTES *clientes)
{
    printf("Nome            NIF\n");
    printf("===========================\n");
    CLIENTE *it = clientes->primeiro;
    while (it != NULL) {
        printf("%-15s %d\n", it->nome, it->NIF);
        it = it->proximo;
    }
}
