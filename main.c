#include "filaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    TFila fila;
    inicializarFila(&fila);
    filaEstaVazia(&fila);
    int elemento = 18;
    inserirFila(&fila, elemento);
    elemento = 5;
    inserirFila(&fila, elemento);
    elemento = -5;
    inserirFila(&fila, elemento);
    return 0;
}