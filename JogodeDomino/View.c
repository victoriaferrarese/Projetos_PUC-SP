#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

void imprimirMenuInicial(){
    printf("\nMENU:\n");
    printf("[1] Nova partida\n");
}
void imprimirMenuJogadores(){
    printf("\nComo deseja jogar?\n");
    printf("[1] Jogador vs Jogador\n");
    printf("[2] Jogador vs IA\n");
}
void imprimirMenuJogadorVsJogador(){
    
    printf("[1] Jogar uma peca\n");
    printf("[2] Comprar uma peca\n");
}
void imprimirOpcaoInvalida(){
    printf("Opcao Invalida!!");
}
void imprimirEscolherPrimeiroJogador(){
    printf("Digite qual jogador comecara a partida (1 ou 2): ");
}
void imprimirMostrarMesa(){
    printf("\n\t\t\t\t\tEssa eh a mesa da partida:\n");
}
void imprimirEscolherPeca(){
    printf("\nDigite o numero da peca que deseja jogar: ");
}
void imprimirJogador1Comeca(){
    printf("\n O jogador 1 possui a maior peca do jogo, logo ele deve comecar a partida.\n");
}
void imprimirJogador2Comeca(){
    printf("\n O jogador 2 possui a maior peca do jogo, logo ele deve comecar a partida.\n");
}
void imprimirPecaInvalida(){
    printf("\n A peca selecionada eh invalida!!\n");
}
void imprimirPilhaVazia(){
    printf("Todas as pecas da pilha ja foram compradas");
}
void imprimirJogador1Vencedor(){
    printf("PARABENS JOGADOR 1, VOCE EH O VENCEDOR DESSA PARTIDA!!\n");
}
void imprimirJogador2Vencedor(){
    printf("PARABENS JOGADOR 2, VOCE EH O VENCEDOR DESSA PARTIDA!!\n");
}
void imprimirMesaTrancada(){
    printf("A mesa esta trancada, não existem jogadas possiveis para que a partida prossiga!\n ");
}
void imprimirPontuacao(){
    printf("Pontuacao dos jogadores calculada com êxito...\n ");
    printf("\t\t\t\t\tPONTUACAO:\n");
}
void imprimirEmpate(){
    printf("EMPATE!!\n");
}