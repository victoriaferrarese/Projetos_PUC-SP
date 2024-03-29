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

        //Carregar Partida Salva
        case 2:

            carregarPartidaSalva(pecas, mesa, partida);
            menuJogadorVsJogador(pecas, mesa, partida);
            
            break;
        
        //Regras
        case 3:

            imprimirRegras();
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
            trocarJogador(partida);
            menuJogadorVsJogador(pecas, mesa, partida);

            break;

        //jogador vs IA
        case 2:
            iniciarJogo(pecas);
            encontrarPrimeiroJogador(pecas, partida, mesa);
            trocarJogador(partida);
            menuJogadorVsIa(pecas, mesa, partida);
            break;

        default:
            imprimirOpcaoInvalida();
            break;
    }

}

void menuJogadorVsJogador(PECA* pecas, PECA* mesa, INFO_GERAL* partida){

        system("cls");
        imprimirMesa(mesa, partida);
        imprimirPecasjogador(pecas, partida);

        int opcaoJogadorVsJogador;
        imprimirescolherOpcaoMenu(partida);
        imprimirMenuJogadorVsJogador();
        scanf("%d", &opcaoJogadorVsJogador);

        switch (opcaoJogadorVsJogador){

            //Jogar uma peca
            case 1:

                jogarPeca(pecas, partida, mesa); 
                trocarJogador(partida);
                
                break;

            //Comprar uma peca
            case 2:
                
                comprarPeca(pecas, partida);
                break;

            //sair 
            case 3:

                sairPartida(pecas,mesa,partida);
                menuInicial(pecas, partida, mesa);
                break;

            default:

                imprimirOpcaoInvalida();
                break;
        }

    if(!fimDeJogo(pecas, mesa, partida)){
        menuJogadorVsJogador(pecas, mesa, partida);
    }
}

void menuJogadorVsIa(PECA* pecas, PECA* mesa, INFO_GERAL* partida){

        system("cls");
        imprimirMesa(mesa, partida);
        imprimirPecasjogador(pecas, partida);

        int opcaoJogadorVsJogador;
        imprimirescolherOpcaoMenu(partida);
        imprimirMenuJogadorVsJogador();
        scanf("%d", &opcaoJogadorVsJogador);

        switch (opcaoJogadorVsJogador){

            //Jogar uma peca
            case 1:

                jogarPeca(pecas, partida, mesa); 
                trocarJogador(partida);
                
                break;

            //Comprar uma peca
            case 2:
                
                comprarPeca(pecas, partida);
                break;

            //sair 
            case 3:

                sairPartida(pecas,mesa,partida);
                menuInicial(pecas, partida, mesa);
                break;

            default:

                imprimirOpcaoInvalida();
                break;
        }

    if(!fimDeJogo(pecas, mesa, partida)){
        menuJogadorVsJogador(pecas, mesa, partida);
    }
}

