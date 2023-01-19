#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "Controller.h"
#include "View.h"

void menuInicial(PECA* pecas, PECAS_MESA* mesa){

    int opcaoMenu;
    imprimirMenuInicial();
    scanf(" %d", &opcaoMenu);

    switch(opcaoMenu){

        //Nova partida
        case 1: 
            menuJogadores(pecas, mesa);
            break;

        //
        case 2:

            
            break;

        default :

            imprimirOpcaoInvalida();
            break;

    }

     menuInicial(pecas, mesa);

}

void menuJogadores(PECA* pecas, PECAS_MESA* mesa){

    int opcaoMenuJogadores;
    imprimirMenuJogadores();
    scanf("%d", &opcaoMenuJogadores);

    switch(opcaoMenuJogadores){

        //jogador vs jogador
        case 1:

            iniciarJogo(pecas);
            menuJogadorVsJogador(pecas, mesa);
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

void menuJogadorVsJogador(PECA* pecas, PECAS_MESA* mesa){

    int jogador = escolherPrimeiroJogador();

    int opcaoJogadorVsJogador;
    imprimirMenuJogadorVsJogador();
    scanf("%d", &opcaoJogadorVsJogador);

    switch (opcaoJogadorVsJogador){

        //Jogar uma peca
        case 1:

            imprimirPecasjogador(pecas,jogador);
            //permitir jogada

            if(jogador == 1)
                jogador = 2;
            else
                jogador = 1;

            break;

        //Comprar uma peca
        case 2:

            comprarPeca(pecas, mesa, jogador);
            break;

        default:

            imprimirOpcaoInvalida();
            break;
    }

    menuJogadorVsJogador(pecas, mesa);
}
