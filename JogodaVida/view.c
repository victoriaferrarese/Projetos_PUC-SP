#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void imprimirAbertura(){
    printf("\n\nBEM-VINDO(A) AO JOGO DA VIDA!!\n\n");
}
void imprimirMenuPrincipal(){
    printf("\nMENU:\n");
    printf("[1] Jogar\n");
    printf("\nSelecione a opcao que deseja: ");
}
void imprimirMenuJogar(){
    printf("\nMENU:\n");
    printf("[1] Definir Seres vivos\n");
    printf("[2] Definir tempo da simulacao\n");
    printf("[3] Simular geracoes\n");
    printf("[4] Limpar mapa\n");
    printf("[5] Sair\n");
    printf("\nSelecione a opcao que deseja: ");
}
void imprimirOpcaoInvalida(){
    printf("\nOpcao invalida!!\n");
}
void imprimirEscolherTamanhoMundo(){
    printf("\nO tamanho do mundo deve ser entre 10 e 60. Escolha o tamanho desse mundo: \n");
}
void imprimirReceberLinha(){
    printf("Linha: ");
}
void imprimirReceberColuna(){
    printf("Coluna: ");
}
void imprimirEscolherQtdSeresVivos(){
    printf("\nQuantos seres vivos deseja colocar no mundo? ");
}
void imprimirEscolherPosicaoSeresVivos(){
    printf("\nDigite a coordenada de cada ser vivo que ira colocar no mundo\n");
}
void imprimirPosicaoInvalida(){
    printf("\nPosicao invalida\n");
}
void imprimirEscolherQtdGeracoes(){
    printf("Determine a quantidade de geracoes que deseja simular: ");
}
void imprimirEscolherVelocidade(){
    printf("\nDetermine o tempo de simulacao das geracoes (em segundos): \n");
}