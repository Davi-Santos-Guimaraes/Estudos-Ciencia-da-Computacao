#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "ListaLinearDE.h"
#include "LerDados.h"

/*===============================================================================================================================
Coloquei umas fuções auxiliares aqui no main pra evitar repetição de código e deixar mais organizado(dar menos trabalho pra mim)
=================================================================================================================================*/
void carregarDados(Tllde *lista, const char *nomeArquivo);

// limpar o buffer do teclado para evitar problemas com fgets e scanf
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//ler strings 
void lerString(char *destino, int tamanho) {
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0'; 
    // strcspn encontra a posição do '\n' e substitui por '\0' para remover a nova linha
}

// Função para adcionar novo aluno via teclado e usar as funções antigas de inserção da lista
Aluno* criarAlunoTeclado() {
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("\nErro de alocacao de memoria para o novo aluno!\n");
        return NULL;
    }
    
    printf("\n--- Cadastrar Novo Aluno ---\n");
    printf("Matricula: ");
    if (scanf("%d", &novo->matricula) != 1) novo->matricula = 0;
    limparBuffer();
    
    printf("Nome: ");
    lerString(novo->nome, 200);
    
    printf("Turno: ");
    lerString(novo->turno, 30);
    
    printf("Periodo: ");
    if (scanf("%d", &novo->periodo) != 1) novo->periodo = 0;
    limparBuffer();
    
    printf("Enfase: ");
    lerString(novo->enfase, 50);
    
    printf("Curso: ");
    lerString(novo->curso, 50);
    
    return novo;
}

// Função para imprimir os dados de um aluno
void imprimirAluno(Aluno *a) {
    if (a == NULL) return;
    printf("\n======== Dados do Aluno ========\n");
    printf("Matricula: %d\n", a->matricula);
    printf("Nome     : %s\n", a->nome);
    printf("Turno    : %s\n", a->turno);
    printf("Periodo  : %d\n", a->periodo);
    printf("Enfase   : %s\n", a->enfase);
    printf("Curso    : %s\n", a->curso);
    printf("================================\n");
}

int main() {
    // Trabalho do krl pra deixar em pt/br e com acentos funcionando no console do windows
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleOutputCP(CP_UTF8);
    
    Tllde lista;
    inicializarLista(&lista);

    // Carrega a lista dos dados dos alunos do arquivo csv
    carregarDados(&lista, "DadosDosAlunos.csv");

    int opcao;
    int posicao;
    Aluno *alunoAux;

    do {
        printf("\n================ MENU DE OPERACOES ================\n");
        printf("1.  Inserir Aluno no INICIO\n");
        printf("2.  Inserir Aluno no FIM\n");
        printf("3.  Inserir Aluno em POSICAO especifica\n");
        printf("4.  Retirar Aluno do INICIO\n");
        printf("5.  Retirar Aluno do FIM\n");
        printf("6.  Retirar Aluno de POSICAO especifica\n");
        printf("7.  Acessar Aluno do INICIO\n");
        printf("8.  Acessar Aluno do FIM\n");
        printf("9.  Acessar Aluno de POSICAO especifica\n");
        printf("10. Exibir Lista Paginada (Inicio ao Fim)\n");
        printf("11. Exibir Lista Paginada (Fim ao Inicio)\n");
        printf("0.  Sair do Programa\n");
        printf("===================================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                alunoAux = criarAlunoTeclado();
                if (alunoAux != NULL) {
                    inserirInicioLLDE(&lista, alunoAux);
                    printf("\nAluno inserido com sucesso no inicio da lista!\n");
                }
                break;

            case 2:
                alunoAux = criarAlunoTeclado();
                if (alunoAux != NULL) {
                    inserirFimLLDE(&lista, alunoAux);
                    printf("\nAluno inserido com sucesso no fim da lista!\n");
                }
                break;

            case 3:
                printf("Informe a posicao de insercao (0 ate %d): ", lista.tamanho);
                if (scanf("%d", &posicao) == 1) {
                    limparBuffer();
                    if (posicao >= 0 && posicao <= lista.tamanho) {
                        alunoAux = criarAlunoTeclado();
                        if (alunoAux != NULL) {
                            inserirPosicaoLLDE(&lista, alunoAux, posicao);
                            printf("\nAluno inserido com sucesso na posicao %d!\n", posicao);
                        }
                    } else {
                        printf("\nPosicao fora dos limites atuais da lista.\n");
                    }
                } else {
                    limparBuffer();
                    printf("\nValor invalido digitado.\n");
                }
                break;

            case 4:
                if (ListaVazia(&lista)) {
                    printf("\nAção nao permitida. A lista esta vazia!\n");
                } else {
                    retirarInicioLLDE(&lista);
                    printf("\nPrimeiro aluno removido com sucesso.\n");
                }
                break;

            case 5:
                if (ListaVazia(&lista)) {
                    printf("\nAção nao permitida. A lista esta vazia!\n");
                } else {
                    retirarFimLLDE(&lista);
                    printf("\nUltimo aluno removido com sucesso.\n");
                }
                break;

            case 6:
                if (ListaVazia(&lista)) {
                    printf("\nAção nao permitida. A lista esta vazia!\n");
                } else {
                    printf("Informe a posicao do aluno a ser retirado (0 ate %d): ", lista.tamanho - 1);
                    if (scanf("%d", &posicao) == 1) {
                        limparBuffer();
                        if (posicao >= 0 && posicao < lista.tamanho) {
                            retirarPosicaoLLDE(&lista, posicao);
                            printf("\nAluno da posicao %d removido com sucesso.\n", posicao);
                        } else {
                            printf("\nPosicao informada e invalida.\n");
                        }
                    } else {
                        limparBuffer();
                        printf("\nValor invalido digitado.\n");
                    }
                }
                break;

            case 7:
                alunoAux = acessarInicioLLDE(&lista);
                if (alunoAux != NULL) {
                    imprimirAluno(alunoAux);
                }
                break;

            case 8:
                alunoAux = acessarFimLLDE(&lista);
                if (alunoAux != NULL) {
                    imprimirAluno(alunoAux);
                }
                break;

            case 9:
                if (ListaVazia(&lista)) {
                    printf("\nA lista esta vazia!\n");
                } else {
                    printf("Informe a posicao que deseja acessar (0 ate %d): ", lista.tamanho - 1);
                    if (scanf("%d", &posicao) == 1) {
                        limparBuffer();
                        if (posicao >= 0 && posicao < lista.tamanho) {
                            alunoAux = acessarPosicaoLLDE(&lista, posicao);
                            imprimirAluno(alunoAux);
                        } else {
                            printf("\nPosicao informada e invalida.\n");
                        }
                    } else {
                        limparBuffer();
                        printf("\nValor invalido digitado.\n");
                    }
                }
                break;

            case 10:
                mostrarLista(&lista, 0);
                break;

            case 11:
                mostrarLista(&lista, 1);
                break;

            case 0:
                printf("\nFinalizando a execucao do sistema...\n");
                break;

            default:
                printf("\nOpcao incorreta. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    // Esvazia e limpa toda a memoria
    while (!ListaVazia(&lista)) {
        retirarInicioLLDE(&lista);
    }

    return 0;
}