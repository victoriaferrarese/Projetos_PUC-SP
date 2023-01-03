#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void imprimirAbertura(){
    printf("\n\nBEM-VINDO(A) AO JOGO DA VIDA!!\n\n");
}
void receberLinha(){
    printf("\nLinha: ");
}
void receberColuna(){
    printf("\nColuna: ");
}
void escolherTamanhoMundo(){
    printf("O tamanho do mundo deve ser entre 10 e 60. Escolha o tamanho desse mundo. \n");
}
void escolherQtdSeresVivos(){
    printf("Quantos seres vivos deseja colocar no mundo?");
}
void escolherPosicaoSeresVivos(){
    printf("Digite a coordenada de cada ser vivo que ira colocar no mundo\n");
}
void imprimirPosicaoInvalida(){
    printf("Posicao invalida");
}