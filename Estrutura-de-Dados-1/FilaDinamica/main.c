#include "filaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    TFila fila;
    inicializarFila(&fila);
    filaEstaVazia(&fila);
    int elemento = 10;
    inserirFila(&fila, elemento);
    int elemento = 40;
    inserirFila(&fila, elemento);
    return 0;
}