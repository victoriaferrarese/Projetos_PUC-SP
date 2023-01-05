#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void imprimirAbertura(){
    printf("\n\nBEM-VINDO(A) AO JOGO DA VIDA!!\n\n");
}
void imprimirMenu(){
    printf("\nMENU:\n");
    printf("[1] Jogar\n");
    printf("[2] Limpar mapa\n");
    printf("[3] simular 1 geracao\n");
    printf("\nSelecione a opcao que deseja: ");
}
void opcaoInvalida(){
    printf("\n Opcao invalida!!\n");
}
void escolherTamanhoMundo(){
    printf("\nO tamanho do mundo deve ser entre 10 e 60. Escolha o tamanho desse mundo. \n");
}
void receberLinha(){
    printf("Linha: ");
}
void receberColuna(){
    printf("Coluna: ");
}
void escolherQtdSeresVivos(){
    printf("\nQuantos seres vivos deseja colocar no mundo? ");
}
void escolherPosicaoSeresVivos(){
    printf("\nDigite a coordenada de cada ser vivo que ira colocar no mundo\n");
}
void imprimirPosicaoInvalida(){
    printf("Posicao invalida\n");
}