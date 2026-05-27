#include "FilaEstatica.h"
int main(void)
{
    TFila filaTeste;
    //Primeiro teste
    printf("\nFila Declarada");
    dadosDaFila(&filaTeste);
    criarFila(4, &filaTeste);
    printf("\nFila Criada e Inicializada");
    dadosDaFila(&filaTeste);
    char *str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);
    //Segundo teste
    enfileirar(105, &filaTeste);
    enfileirar(205, &filaTeste);
    enfileirar(305, &filaTeste);
    enfileirar(405, &filaTeste);
    printf("Fila esta cheia? %d",filaEstaCheia(&filaTeste));
    enfileirar(505, &filaTeste);
    printf("\nFila com dados incluidos");
    dadosDaFila(&filaTeste);
    str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);    
    dadosDaFila(&filaTeste);
    // Apagando dados da Fila
    desenfileirar(&filaTeste);
    desenfileirar(&filaTeste);
    desenfileirar(&filaTeste);
    enfileirar(550,&filaTeste);
    enfileirar(660,&filaTeste);
    str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);  

    printf("\nFila com dados incluidos/excluidos");
    dadosDaFila(&filaTeste);



    liberarFila(&filaTeste);
}