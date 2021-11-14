//
// Created by Nuno on 14/11/2021.
//

#ifndef PROJETOLP_AED_CLIENTES_H
#define PROJETOLP_AED_CLIENTES_H

typedef struct cliente {
    char nome[128];
    int NIF;
    int contacto;
    struct cliente *proximo;
} CLIENTE;

typedef struct clientes {
    CLIENTE *primeiro;
} CLIENTES;

CLIENTES *criar_clientes();

CLIENTE *criar_cliente(char *nome, int NIF, int contacto);
void inserir_cabeca(CLIENTES *clientes, CLIENTE *cliente);
void inserir_cauda(CLIENTES *clientes, CLIENTE *cliente);
void inserir_ordenado_NIF(CLIENTES *clientes, CLIENTE *cliente);
void inserir_ordenado_nome(CLIENTES *clientes, CLIENTE *cliente);

CLIENTE *pesquisar_NIF(CLIENTES *clientes, int NIF);
CLIENTE *pesquisar_nome(CLIENTES *clientes, char *nome);

void remover_cliente(CLIENTES *clientes, CLIENTE *cliente);

void imprimir_clientes(CLIENTES *clientes);

#endif //PROJETOLP_AED_CLIENTES_H
