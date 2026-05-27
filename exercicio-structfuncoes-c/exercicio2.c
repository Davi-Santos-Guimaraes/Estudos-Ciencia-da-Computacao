#include <stdio.h>
#include <string.h>

struct Estudante {
    char nome[50];
    long int matricula;
    char nasc[11];
    float notas[4];
};

int main() {
    int nAluno, i, j;
    printf("Digite o numero de alunos: ");
    scanf("%d", &nAluno);
    struct Estudante alunos[nAluno];

    for (i = 0; i < nAluno; i++) {
        getchar();
        printf("Digite o nome do %dº aluno: ", i + 1);
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        printf("Digite a matricula do aluno: ");
        scanf("%ld", &alunos[i].matricula);
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        getchar();
        fgets(alunos[i].nasc, 11, stdin);
        alunos[i].nasc[strcspn(alunos[i].nasc, "\n")] = '\0';
        printf("Digite as notas das 4 disciplinas:\n");
        for (j = 0; j < 4; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
    }

    printf("\nRelatorio de Alunos:\n");

    for (i = 0; i < nAluno; i++) {
        float soma = 0.0;
        for (j = 0; j < 4; j++) {
            soma += alunos[i].notas[j];
        }
        float media = soma / 4;
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %ld\n", alunos[i].matricula);
        printf("Data de Nascimento: %s\n", alunos[i].nasc);
        printf("Media Geral: %.2f\n", media);
        if (media >= 7.0) {
            printf("Status: Aprovado\n");
        } else {
            printf("Status: Reprovado\n");
        }
    }

    return 0;
}
