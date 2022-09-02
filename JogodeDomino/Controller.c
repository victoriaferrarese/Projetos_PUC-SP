#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "Controller.h"
#include "View.h"

void interface(pecaInfo pecas[])
{
    int sentinela = 0;

    do{
        imprimirMenuPrincipal();
        int opcao = opcaoSelecionadaMenuPrincipal(); //Jogar / Retomar Partida / Salvar Partida / Carregar Partida Salva / Regras / Sair 

        switch(opcao){ //switch Menu Principal
            
            case 1: //Jogar
                int opcaoJogar = opcaoSelecionadaMenuJogar(); //Jogador vs Jogador / Jogador vs IA

                switch(opcaoJogar){ //Switch Menu Jogar

                    case 1: // Jogador vs Jogador 
                        iniciarJogo(); //gerarPecas / embaralharPecas / distribuirPecas(em desenvolvimento)
                        imprimirMenuPartida();

                        int opcaoPartida = opcaoSelecionadaMenuPartida(); // jogarPeca / comprarPeca / Menu Principal (break para o Menu Principal)

                            switch(opcaoPartida){ //Switch Menu Partida

                                case 1: //Jogar Peca
                                    break;

                                case 2: // Comprar Peca
                                    break;
                                
                                case 3: //Voltar ao Menu Principal
                                    break;

                                default:
                                    break;
                            }                        
                        /*
                        imprimirPecas(pecas);
                        imprimirPecasEmbaralhadas(pecas);
                        desembaralharPecas(pecas);
                        imprimirPecas(pecas);
                        */

                        break;
                    case 2: // Jogador vs IA 
                         
                         break;
                    
                    default:

                        break;
                    
                }
                
                break;

            case 2: //Retomar Partida
                
                break;

            case 3: //Salvar Partida
                
                break;

            case 4: //Carregar Partida Salva
                
                break;
            
            case 5: //Regras

                break;
            
            case 6: //Sair

                break;

            default:
                sentinela = 0;
                break;
        }

    }while(sentinela != 1);

}
