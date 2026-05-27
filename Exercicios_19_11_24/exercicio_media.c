#include <stdio.h>

void calcular_media(float (*notas)[3], float *media)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        media[i] = (notas[i][0] + notas[i][1] + notas[i][2]) / 3;
    }
}

int main()
{
    int i, j, acima_de_sete = 0;
    float notas[5][3], media[5];
    char alunos[5][50];

    for (i = 0; i < 5; i++)
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]", alunos[i]);
        for (j = 0; j < 3; j++)
        {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
        printf("\n");
    }

    calcular_media(notas, media);

    for (i = 0; i < 5; i++)
    {
        printf("Aluno %d: %s\n", i + 1, alunos[i]);
        printf("Notas: %.2f, %.2f, %.2f\n", notas[i][0], notas[i][1], notas[i][2]);
        printf("Média: %.2f\n", media[i]);

        if (media[i] > 7.0)
        {
            acima_de_sete++;
        }
    }

    printf("Quantidade de alunos com média acima de 7: %d\n", acima_de_sete);

    return 0;
}
