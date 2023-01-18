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

        //Jogar
        case 1: 
            
            break;

        //
        case 2:

            
            break;

        default :

            imprimirOpcaoInvalida();
            break;

    }

     menuInicial(pecas);

}

void menuJogar(PECA* pecas){

    int opcaoMenuJogar;
    scanf("%d", &opcaoMenuJogar);

    switch(opcaoMenuJogar){

        //jogador vs jogador
        case 1:
            break;

        //jogador vs IA
        case 2:
            break;

        default:
            imprimirOpcaoInvalida();
            break;
    }

    menuJogar(pecas);
}
