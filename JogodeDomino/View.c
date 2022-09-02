#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

void imprimirMenuPrincipal(){
    
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("[1] -> Jogar\n");
    printf("[2] -> Retomar Partida\n");
    printf("[3] -> Salvar Partida\n");
    printf("[4] -> Carregar Partida Salva\n");
    printf("[5] -> Regras\n");
    printf("[6] -> Sair\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
    printf("Digite a opcao desejada: ");                  
}

void imprimirMenuJogar(){

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("[1] -> Jogador vs Jogador\n");
    printf("[2] -> Jogador vs IA\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Digite a opcao desejada: ");    

}

void imprimirMenuPartida(){
    //printf("Vez do Jogador %c", Jogador); //indica qual jogador jogara
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("[1]Jogar peca\n"); // peca que sera jogada
    printf("[2]Comprar peca\n"); // comprar peca
    printf("[3]Voltar ao Menu Principal");  //Menu Principal
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
}

void imprimirPecas(pecaInfo pecas[]){

    printf("As pecas de Domino sao:\n");
    for(int i = 0; i < 28; i++)
    {
        if (i < 9)
        {
            printf("#%d   ->  %d | %d\n",i+1, pecas[i].numero1,pecas[i].numero2);
        }
        else
        {
            printf("#%d  ->  %d | %d\n",i+1, pecas[i].numero1,pecas[i].numero2);
        }
    }
    printf("\n\n\n");
}

void imprimirPecasEmbaralhadas(pecaInfo pecas[]){
    
    for(int i = 0; i < 28; i++)
    {
        if (i < 9)
        {
            printf("Peca aleatoria #%d   ->  %d | %d\n", i+1, pecas[pecas[i].posicao].numero1, pecas[pecas[i].posicao].numero2);
        }
        else
        {
            printf("Peca aleatoria #%d  ->  %d | %d\n", i+1, pecas[pecas[i].posicao].numero1, pecas[pecas[i].posicao].numero2);
        }
    }
}
