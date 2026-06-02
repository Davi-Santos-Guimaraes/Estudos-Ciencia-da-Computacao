#include "listaLinearSE.h"

int main(){
    //inicializar lista
    Tllse lista;
    inicializarLista(&lista);

    //menu
    int opcao = 1;
    int posicao;
    while (opcao!=0){
        printf("\n=======================MENU==========================\n");
        printf("\nEscolha a opcao que deseja:\n1-inserir na posicao\n2-remover na posicao\n3-acessar posicao\n4-mostrar lista\n\n0-Sair\n");
        scanf("%d",&opcao);
        if(opcao==1){
            printf("\nDigite a posicao desejada:\n");
            scanf("%d",&posicao);
            int elemento;
            printf("\nDigite o elemento que deseja inserir:\n");
            scanf("%d",&elemento);
            inserirPosicaollse(&lista,elemento,posicao);
        }
        if(opcao==2){
            printf("\nDigite a posicao desejada:\n");
            scanf("%d",&posicao);
            retirarPosicaollse(&lista,posicao);
        }
        if(opcao==3){

            printf("\nDigite a posicao desejada:\n");
            scanf("%d",&posicao);
            int valor = acessarPosicaollse(&lista,posicao);
            printf("\nValor na posicao %d: %d\n", posicao, valor);
            
        }
        if(opcao==4){
            mostrarLista(&lista);
        }


    }
    

}