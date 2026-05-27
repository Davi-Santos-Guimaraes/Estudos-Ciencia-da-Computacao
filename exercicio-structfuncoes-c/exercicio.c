#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct estudante {
    char nome[50];
    int idade;
    float nota;
};

void inserirDados(struct estudante *e) {
    getchar();
    printf("Digite o nome do estudante: ");
    fgets(e->nome, 50, stdin);
    e->nome[strcspn(e->nome, "\n")] = '\0';
    printf("Digite a idade do estudante: ");
    scanf("%d", &e->idade);
    printf("Digite a nota do estudante: ");
    scanf("%f", &e->nota);
}

void atualizarNota(struct estudante *e, float novaNota) {
    e->nota = novaNota;
    printf("Nota Atualizada.\n");
}

void mostrarDados(struct estudante e) {
    printf("Nome: %s\n", e.nome);
    printf("Idade: %d\n", e.idade);
    printf("Nota: %.2f\n", e.nota);
}

int main() {
    int opcao = 1, numEst = 0, n;
    struct estudante c[50];
    float nota;

    while (opcao) {
        printf("Digite o numero para acao desejada:\n");
        printf("1-Inserir novo Estudante.\n");
        printf("2-Atualizar nota de um Estudante.\n");
        printf("3-Mostrar informacoes de um estudante.\n");
        printf("0-Sair do programa.\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (numEst < 50) {
                inserirDados(&c[numEst]);
                numEst++;
            } else {
                printf("Numero maximo de estudantes atingido.\n");
            }
        } else if (opcao == 2) {
            printf("Digite o numero do estudante que deseja alterar (entre 0 e %d).\n", numEst - 1);
            scanf("%d", &n);
            if (n >= 0 && n < numEst) {
                printf("Digite a nova nota: ");
                scanf("%f", &nota);
                atualizarNota(&c[n], nota);
            } else {
                printf("Aluno nao encontrado!\n");
            }
        } else if (opcao == 3) {
            printf("Digite o numero do estudante que deseja ver (entre 0 e %d).\n", numEst - 1);
            scanf("%d", &n);
            if (n >= 0 && n < numEst) {
                mostrarDados(c[n]);
            } else {
                printf("Aluno nao encontrado!\n");
            }
        } else if (opcao == 0) {
            printf("Saindo do programa.\n");
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
