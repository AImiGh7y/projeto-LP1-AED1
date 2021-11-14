#include <stdio.h>
#include "clientes.h"

int main() {
    /*
     * CLIENTE *criar_cliente(char *nome, int NIF, int contacto);
void inserir_cabeca(CLIENTES *clientes, CLIENTE *cliente);
void inserir_cauda(CLIENTES *clientes, CLIENTE *cliente);
void inserir_ordenado_NIF(CLIENTES *clientes, CLIENTE *cliente);
void inserir_ordenado_nome(CLIENTES *clientes, CLIENTE *cliente);

     */

    CLIENTES *clientes = criar_clientes();

    inserir_cauda(clientes, criar_cliente("Rodrigo", 3423323, 93435323));
    inserir_cauda(clientes, criar_cliente("Maria", 435343, 91435323));
    inserir_cauda(clientes, criar_cliente("Jose", 553435532, 96435323));

    imprimir_clientes(clientes);

    return 0;
}
