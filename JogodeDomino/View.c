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
    printf("\nO que deseja fazer?\n");
    printf("[1] Jogar uma peca\n");
    printf("[2] Comprar uma peca\n");
}
void imprimirOpcaoInvalida(){
    printf("Opcao Invalida!!");
}

void imprimirEscolherPrimeiroJogador(){
    printf("Digite qual jogador comecara a partida (1 ou 2): ");
}

void imprimirMostrarPecas(){
    printf("\n\t\t\t\t\tEssas sao as suas pecas:\n\n ");
}