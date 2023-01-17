#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "Controller.h"
#include "View.h"

void menuInicial(PECA* pecas){

    int opcaoMenu;
    imprimirMenuInicial();
    scanf(" %d", &opcaoMenu);

    switch(opcaoMenu){

        //gerar/organizar pecas
        case 1: 

            inicializarPecas(pecas);
            imprimirPecas(pecas);
            break;

        //embaralhar pecas
        case 2:

            embaralharPecas(pecas);
            imprimirPecas(pecas);
            break;

        default :

            imprimirOpcaoInvalida();
            break;

    }

     menuInicial(pecas);

}
