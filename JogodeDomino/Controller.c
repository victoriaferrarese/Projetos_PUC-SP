#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "Controller.h"
#include "View.h"

void MenuPrincipal(pecaInfo pecas[]){

    int sentinela = 0;

    do{
        imprimirMenuPrincipal();
        int opcaoPrincipal = opcaoMenuPrincipal();

        switch(opcaoPrincipal){ //switch Menu Principal
            
            case 1: ;//Jogar
                MenuJogar(pecas);
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

void MenuJogar(pecaInfo pecas[]){

    int opcaoJogar = opcaoMenuJogar();

    switch(opcaoJogar){ //Switch Menu Jogar

        case 1: // Jogador vs Jogador 
            iniciarJogo(pecas); //gerarPecas / embaralharPecas / distribuirPecas(em desenvolvimento)
            imprimirMenuPartida();
            MenuPartida(pecas);

            break;
        case 2: // Jogador vs IA 
            
                break;
    
        default:

            break;
    }
}
void MenuPartida(pecaInfo pecas[]){

    int opcaoPartida = opcaoMenuPartida();

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

}
