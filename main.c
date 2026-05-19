#include "listaLinearSE.h"

int main(){
    //inicializar lista
    Tllse lista;
    inicializarLista(&lista);

    //Primeiros Testes
    retirarIniciollse(&lista);
    inserirIniciollse(&lista,10);
    inserirIniciollse(&lista,-5);
    inserirIniciollse(&lista,100);
    printf("\n%d",acessarIniciollse(&lista));
    retirarIniciollse(&lista);
    printf("\n%d",acessarIniciollse(&lista));
    retirarIniciollse(&lista);
    printf("\n%d",acessarIniciollse(&lista));
    retirarIniciollse(&lista);
}