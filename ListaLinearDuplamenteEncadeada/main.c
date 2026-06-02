#include "ListaLinearDE.h"

int main(){
    Tllde(lista);
    inicializarLista(&lista);

    inserirInicioLLDE(&lista, 40);
    inserirInicioLLDE(&lista, 30);
    inserirInicioLLDE(&lista, 50);
    mostrarLista(&lista,0);
    mostrarLista(&lista,1);

    printf("\n%d",acessarInicioLLDE(&lista));
    retirarInicioLLDE(&lista);

    printf("\n%d",acessarInicioLLDE(&lista));
    retirarInicioLLDE(&lista);

    printf("\n%d",acessarInicioLLDE(&lista));
    retirarInicioLLDE(&lista);

    retirarInicioLLDE(&lista);
    printf("\n%d",acessarInicioLLDE(&lista));

    inserirInicioLLDE(&lista, 10);
    inserirInicioLLDE(&lista, 20);
    inserirInicioLLDE(&lista, 30);

    mostrarLista(&lista,0);
    mostrarLista(&lista,1);

    
    retirarInicioLLDE(&lista);
    retirarInicioLLDE(&lista);
    retirarInicioLLDE(&lista);
    
}