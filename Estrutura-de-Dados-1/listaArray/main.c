#include <stdio.h>
#include "listaArray.h"

/*int main(void){
    Tlista lista;
    mostrarDados(&lista);
    printf("**********************");
    inicializar(&lista, 7);
    printf("**********************");
    printf("Lista Vazia= %d\n", listaEstaVazia(&lista));
    printf("**********************");
    printf("Lista Cheia= %d\n", listaEstaCheia(&lista));
    printf("**********************");
    liberarLista(&lista);
}
    */


int main(void){
    Tlista lista;
    int tamanho =5;
    int opcao = 0;
    int elemento;
    int posicao;
    inicializar(&lista, tamanho);

    do{
        
        printf("\n\nMenu:\n");

        printf("**********************\n");
        printf("INICIO DA LISTA\n");
        printf("1. Inserir no inicio\n");
        printf("2. Acessar no inicio\n");
        printf("3. Remover no inicio\n");

        printf("**********************\n");
        printf("FIM DA LISTA\n");
        printf("4. Inserir no fim\n");
        printf("5. Acessar no fim\n");
        printf("6. Remover no fim\n");

        printf("**********************\n");
        printf("POSICAO ESPECIFICA DA LISTA\n");
        printf("7. Inserir em uma posicao especifica\n");
        printf("8. Acessar uma posicao especifica\n");
        printf("9. Remover em uma posicao especifica\n");
        
        printf("**********************\n");
        printf("Parte da prova\n");
        printf("11. Remover elemento\n");
        printf("12. Inserir Ordenado\n");
    
        printf("**********************\n");
        printf("10. Mostrar lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("**********************\n"); 

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido no inicio: ");
                scanf("%d", &elemento);
                if (inserirInicioLista(&lista, elemento)) {
                    printf("Elemento inserido no inicio.\n");
                }
                break;
            case 2:
                printf("Elemento no inicio: %d\n", acessarInicioLista(&lista));
                break;
            case 3:
                removerInicioLista(&lista);
                break;
            case 4:
                printf("Digite o elemento a ser inserido no fim: ");
                scanf("%d", &elemento);
                if (inserirFimLista(&lista, elemento)) {
                    printf("Elemento inserido no fim.\n");
                }
                break;
            case 5:
                printf("Elemento no fim: %d\n", acessarFimLista(&lista));
                break;
            case 6:
                removerFimLista(&lista);
                break;
            case 7:
                printf("Digite a posicao desejada: ");
                scanf("%d",&posicao);
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                inserirPosicao(&lista, posicao, elemento);
                break;
            case 8:
                if (listaEstaVazia(&lista)) {
                  printf("A lista esta vazia!\n");
                } else {
                   printf("Digite a posicao desejada: ");
                   scanf("%d", &posicao);
                   if (posicao >= 0 && posicao < lista.ocupacao) {
                   printf("Elemento na posicao %d: %d\n", posicao, acessarPosicao(&lista, posicao));
                } else {
                    printf("Posicao invalida!\n");
                }
    }
    break;
            case 9:
                printf("Digite a posicao desejada: ");
                scanf("%d",&posicao);
                removerPosicao(&lista, posicao);
                break;

            case 10:
                mostrar(&lista);
                break;
            case 0:
                liberarLista(&lista);
                printf("Saindo...\n");
                break;
            case 11:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento);
                removerElemento(&lista, elemento);
                break;
            case 12:
                printf("Digite o elemento a ser inserido de forma ordenada: ");
                scanf("%d", &elemento);
                inserirOrdenado(&lista, elemento);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    }while (opcao != 0);

    return 0;
}