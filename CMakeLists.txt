cmake_minimum_required(VERSION 3.20)
project(ProjetoLP_AED C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetoLP_AED main.c clientes.c clientes.h viagem.c viagem.h cidade.c cidade.h poi.c poi.h consulta.c consulta.h disco.c disco.h)
