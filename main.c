#include <stdio.h>
#include "clientes.h"

int main() {
    CLIENTES *clientes = criar_clientes();

    inserir_ordenado_NIF(clientes, criar_cliente("Maria",   4353431, 91435323));
    inserir_ordenado_NIF(clientes, criar_cliente("Rodrigo", 3423323, 93435323));
    inserir_ordenado_NIF(clientes, criar_cliente("Jose",    5534355, 96435323));
    inserir_ordenado_NIF(clientes, criar_cliente("Carlos",  7534355, 96435323));
    inserir_ordenado_NIF(clientes, criar_cliente("Ana",     2534355, 96435323));
    inserir_ordenado_NIF(clientes, criar_cliente("Beatriz", 1534355, 96435323));

    imprimir_clientes(clientes);

    //////////////////////////////////////////////////////////////

    CLIENTE *c = pesquisar_nome(clientes, "Beatriz");
    VIAGEM *v0 = inserir_viagem_no_cliente(c);
    VIAGEM *v1 = inserir_viagem_no_cliente(c);
    VIAGEM *v2 = inserir_viagem_no_cliente(c);

    adicionar_cidade_a_viagem(v1, "Porto", "");
    adicionar_cidade_a_viagem(v1, "Lisboa", "");
    adicionar_cidade_a_viagem(v1, "Coimbra", "");
    adicionar_cidade_a_viagem(v1, "Braga", "");
    imprimir_viagem(v1);

    return 0;
}
