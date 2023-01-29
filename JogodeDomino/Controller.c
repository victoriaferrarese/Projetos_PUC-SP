#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "Controller.h"
#include "View.h"

void menuInicial(PECA* pecas, INFO_GERAL* partida, PECA* mesa){

    int opcaoMenu;
    imprimirMenuInicial();
    scanf(" %d", &opcaoMenu);

    switch(opcaoMenu){

        //Nova partida
        case 1: 
            menuJogadores(pecas, partida, mesa);
            break;

        //
        case 2:

            
            break;

        default :

            imprimirOpcaoInvalida();
            break;

    }

     menuInicial(pecas, partida, mesa);

}

void menuJogadores(PECA* pecas, INFO_GERAL* partida, PECA* mesa){

    int opcaoMenuJogadores;
    imprimirMenuJogadores();
    scanf("%d", &opcaoMenuJogadores);

    switch(opcaoMenuJogadores){

        //jogador vs jogador
        case 1:

            iniciarJogo(pecas);
            encontrarPrimeiroJogador(pecas, partida, mesa);
            menuJogadorVsJogador(pecas, partida);

            break;

        //jogador vs IA
        case 2:
            iniciarJogo(pecas);
            break;

        default:
            imprimirOpcaoInvalida();
            break;
    }

}

void menuJogadorVsJogador(PECA* pecas,INFO_GERAL* partida){

    imprimirPecasjogador(pecas, partida);

    int opcaoJogadorVsJogador;
    imprimirMenuJogadorVsJogador();
    scanf("%d", &opcaoJogadorVsJogador);

    switch (opcaoJogadorVsJogador){

        //Jogar uma peca
        case 1:

            //permitir jogada
            trocarJogador(partida);
            
            break;

        //Comprar uma peca
        case 2:
            
            comprarPeca(pecas, partida);
            break;

        default:

            imprimirOpcaoInvalida();
            break;
    }

    menuJogadorVsJogador(pecas, partida);
}
