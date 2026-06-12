#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LerDados.h"
#include "ListaLinearDE.h" // Precisa incluir para reconhecer Tllde e inserirFimLLDE

/*==================================================
Função para ler dados do banco de dados dos alunos
=====================================================*/
void carregarDados(Tllde *lista, const char *nomeArquivo) {
    // 1. Abre o arquivo em modo de leitura ("r" - read)
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo %s. Verifique se ele esta na mesma pasta.\n", nomeArquivo);
        return;
    }

    // Buffer (espaço temporário) grande o suficiente para caber a maior linha do CSV
    char linha[500]; 

    // 2. O fgets vai ler linha por linha até chegar no final do arquivo (NULL)
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        
        // 3. Aloca memória APENAS para a struct do aluno. A lista guardará esse ponteiro!
        Aluno *novoAluno = (Aluno*) malloc(sizeof(Aluno));
        if (novoAluno == NULL) {
            printf("\nErro: Memoria insuficiente para carregar aluno!\n");
            continue; // Pula para a próxima linha se der erro
        }

        /* 4. Começa a "fatiar" a linha usando o ponto e vírgula ";" como faca */
        
        // Fatiando a Matrícula
        char *token = strtok(linha, ";");
        if(token) novoAluno->matricula = atoi(token); // atoi converte texto para número inteiro (int)

        // Fatiando o Nome
        token = strtok(NULL, ";"); // Passar NULL diz ao strtok para continuar de onde parou
        if(token) strcpy(novoAluno->nome, token);

        // Fatiando o Turno
        token = strtok(NULL, ";");
        if(token) strcpy(novoAluno->turno, token);

        // Fatiando o Período
        token = strtok(NULL, ";");
        if(token) novoAluno->periodo = atoi(token);

        // Fatiando a Ênfase
        token = strtok(NULL, ";");
        if(token) strcpy(novoAluno->enfase, token);

        // Fatiando o Curso (Atenção aqui: o separador agora é a quebra de linha "\n" ou "\r", e não o ";")
        token = strtok(NULL, "\r\n"); 
        if(token) strcpy(novoAluno->curso, token);

        /* 5. Insere o endereço de memória do aluno na Lista */
        // Usamos inserir no fim para que a lista fique na mesma ordem do arquivo original
        inserirFimLLDE(lista, novoAluno); 
    }

    // 6. Fecha o arquivo para liberar o recurso do sistema operacional
    fclose(arquivo);
    printf("\n>>> Carga concluida! Total de %d alunos carregados na lista. <<<\n", lista->tamanho);
}