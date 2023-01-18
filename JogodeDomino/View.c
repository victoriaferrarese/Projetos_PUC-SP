#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

void imprimirMenuInicial(){
    printf("\nMENU:\n");
    printf("[1] Jogar\n");
}

void imprimirMenuJogadores(){
    printf("\nComo deseja jogar?\n");
    printf("[1] Jogador vs Jogador\n");
    printf("[2] Jogador vs IA\n");
}

void imprimirOpcaoInvalida(){
    printf("Opcao Invalida!!");
}