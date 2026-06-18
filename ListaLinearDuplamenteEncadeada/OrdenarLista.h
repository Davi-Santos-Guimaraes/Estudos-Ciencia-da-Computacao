#ifndef ORDENAR_LISTA_H
#define ORDENAR_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "ListaLinearDE.h"
#include "LerDados.h"

/*==================================================
Funções para ordenação de listas
==================================================*/

void ordenarPorMatricula(Tllde *lista);
void ordenarPorNome(Tllde *lista);
void ordenarPorCursoENome(Tllde *lista);
void ordenarPorEnfaseENome(Tllde *lista);

#endif