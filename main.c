#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDinamica.h"
#include "resolucaoAluno.h"

static int lerLinha(FILE *arquivo, char *linha, size_t tamanho) {
    int c;
    size_t i = 0;
    int gotChar = 0;

    while ((c = fgetc(arquivo)) != EOF) {
        gotChar = 1;
        if (c == '\r' || c == '\n') {
            if (c == '\r') {
                int next = fgetc(arquivo);
                if (next != EOF && next != '\n') {
                    ungetc(next, arquivo);
                }
            }
            break;
        }
        if (i + 1 < tamanho) {
            linha[i++] = (char)c;
        }
    }

    if (i < tamanho) {
        linha[i] = '\0';
    } else {
        linha[tamanho - 1] = '\0';
    }

    return gotChar || i > 0;
}

int main() {
    //Inicializa a fila
    TFila fila;
    inicializarFila(&fila);

    //Abre o arquivo
    FILE *arquivo = fopen("ArquivoAlunos_28_33_120_csv.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo CSV!\n");
        return 1;
    }

    char linha[520];
    char *matricula;
    char *nome;

    printf("\n\nLendo dados do arquivo e inserindo na fila...\n");

    // Lê o arquivo linha por linha
    while (lerLinha(arquivo, linha, sizeof(linha))) {
        matricula = strtok(linha, ";");
        nome = strtok(NULL, ";");

        if (matricula != NULL && nome != NULL) {
            // Cria um novo aluno e insere na fila
            TAluno *novoAluno = criarAluno(matricula, nome);
            if (novoAluno != NULL) {
                inserirFila(&fila, novoAluno);
            }
        }
    }

    // Fecha o arquivo após a leitura
    fclose(arquivo);

    // 4. Processa a fila
    printf("\n--- Conteudo da Fila ---\n");
    processarImprimirFila(&fila);
    printf("\n\n");

    return 0;
}