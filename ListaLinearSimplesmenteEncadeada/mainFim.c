#include "listaLinearSE.h"

int main(){
    //inicializar lista
    printf("\nCriar Lista");
    Tllse lista;
    printf("\nInicializa Lista");
    inicializarLista(&lista);

    //Primeiros Testes
    printf("\n\n================== Teste da lista ==================\n");

    printf("\nMostrar Lista:");
    mostrarLista(&lista);

    printf("\nRetira no fim da Lista");
    retirarFimllse(&lista);

    printf("\nAcessar fim da Lista:");
    acessarFimllse(&lista);

    //Testes de inserir acessar e retirar

    printf("\nInserir no fim da Lista");
    inserirFimllse(&lista, 10);

    printf("\nInserir no fim da Lista");
    inserirFimllse(&lista, 20);

    printf("\nMostrar Lista:");
    mostrarLista(&lista);

    printf("\nAcessar fim da Lista:");
    printf("\n%d",acessarFimllse(&lista));

    printf("\nRetira no fim da Lista");
    retirarFimllse(&lista);

    printf("\nRetira no fim da Lista");
    retirarFimllse(&lista);

    printf("\nInserir no fim da Lista");
    inserirFimllse(&lista, 99);

    printf("\nInserir no fim da Lista");
    inserirFimllse(&lista, 100);

    printf("\nMostrar Lista:");
    mostrarLista(&lista);

}