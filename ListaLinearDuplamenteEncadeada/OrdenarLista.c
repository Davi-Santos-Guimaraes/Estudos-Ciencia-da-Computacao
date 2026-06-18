#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OrdenarLista.h"

/*==================================================
Funções internas de comparação
==================================================*/
int compararMatricula(Aluno *a, Aluno *b) {
    return a->matricula - b->matricula;
}

int compararNome(Aluno *a, Aluno *b) {
    return strcmp(a->nome, b->nome);
}

int compararCursoENome(Aluno *a, Aluno *b) {
    int comp = strcmp(a->curso, b->curso);
    if (comp == 0) {
        return strcmp(a->nome, b->nome);
    }
    return comp;
}

int compararEnfaseENome(Aluno *a, Aluno *b) {
    int comp = strcmp(a->enfase, b->enfase);
    if (comp == 0) {
        return strcmp(a->nome, b->nome);
    }
    return comp;
}

/*==================================================
Lógica central de ordenação (Bubble Sort otimizado para Lista)
Troca apenas as cargas (ponteiros de Aluno) entre os nós.
==================================================*/
void ordenarLista(Tllde *lista, int (*comparar)(Aluno*, Aluno*)) {
    if (lista == NULL || lista->tamanho < 2) {
        return; // Lista vazia ou com apenas 1 elemento já está ordenada
    }

    int trocou;
    TNo *atual;
    TNo *ultimo = NULL; // Otimização para não checar o final já ordenado

    do {
        trocou = 0;
        atual = lista->inicio;

        while (atual->proximo != ultimo) {
            // Se o elemento atual for maior que o próximo, troca as cargas
            if (comparar(atual->aluno, atual->proximo->aluno) > 0) {
                Aluno *temp = atual->aluno;
                atual->aluno = atual->proximo->aluno;
                atual->proximo->aluno = temp;
                trocou = 1;
            }
            atual = atual->proximo;
        }
        ultimo = atual;
    } while (trocou);
}

/*==================================================
Implementações públicas
==================================================*/
void ordenarPorMatricula(Tllde *lista) {
    ordenarLista(lista, compararMatricula);
}

void ordenarPorNome(Tllde *lista) {
    ordenarLista(lista, compararNome);
}

void ordenarPorCursoENome(Tllde *lista) {
    ordenarLista(lista, compararCursoENome);
}

void ordenarPorEnfaseENome(Tllde *lista) {
    ordenarLista(lista, compararEnfaseENome);
}