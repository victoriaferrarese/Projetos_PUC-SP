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

        //Nova partida
        case 1: 
            menuJogadores(pecas);
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

void menuJogadores(PECA* pecas){

    int opcaoMenuJogadores;
    imprimirMenuJogadores();
    scanf("%d", &opcaoMenuJogadores);

    switch(opcaoMenuJogadores){

        //jogador vs jogador
        case 1:

            iniciarJogo(pecas);
            menuJogadorVsJogador(pecas);
            break;

        //jogador vs IA
        case 2:
            iniciarJogo(pecas);
            break;

        default:
            imprimirOpcaoInvalida();
            break;
    }

    menuJogadores(pecas);
}

void menuJogadorVsJogador(PECA* pecas){

    int primeiroJogador = escolherPrimeiroJogador();

    int opcaoJogadorVsJogador;
    imprimirMenuJogadorVsJogador();
    scanf("%d", &opcaoJogadorVsJogador);

    switch (opcaoJogadorVsJogador){

    case 1:

        imprimirPecasjogador(pecas,primeiroJogador);
        
        break;
    
    default:
        break;
    }
}
