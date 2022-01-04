#include <stdio.h>
#include "clientes.h"
#include "disco.h"
#include "ag.h"

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

    CIDADE *c1 = criar_cidade("Porto", "", 41.1495, -8.6108);
    CIDADE *c2 = criar_cidade("Lisboa", "", 38.7452,	-9.1604);
    CIDADE *c3 = criar_cidade("Coimbra", "", 40.2111, -8.4291);
    CIDADE *c4 = criar_cidade("Aveiro", "", 40.6389, -8.6553);
    CIDADE *c5 = criar_cidade("Braga", "", 41.5333, -8.4167);
    CIDADE *cidades[] = {c1, c2, c3, c4, c5};

    //////////////////////////////////////////////////////////////

    CLIENTE *c = pesquisar_nome(clientes, "Beatriz");
    VIAGEM *v0 = inserir_viagem_no_cliente(c);
    VIAGEM *v1 = inserir_viagem_no_cliente(c);
    VIAGEM *v2 = inserir_viagem_no_cliente(c);

    adicionar_cidade_a_viagem(v1, c1);
    adicionar_cidade_a_viagem(v1, c3);
    adicionar_cidade_a_viagem(v1, c2);
    adicionar_cidade_a_viagem(v1, c4);
    imprimir_viagem(v1);

    escrever_ficheiros_txt(clientes);

    //////////////////////////////////////////////////////////////

    AG *ag = ag_criar(5, 0.01, 2, 50, 5);
    GERACAO *g = ag_criar_geracao_aleatoria(ag, cidades);

    for(int i = 0; i < 5; i++) {
        VIAGEM *viagem = g->progenitores[i];
        imprimir_viagem(viagem);
        printf("aptidao: %f\n", calcular_aptidao(viagem));
    }



    return 0;
}
