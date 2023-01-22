#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

void iniciarJogo(PECA* pecas){
    inicializarPecas(pecas);
    embaralharPecas(pecas);
    distribuirPecas(pecas);
    
}
void inicializarPecas(PECA* pecas){
    
    int i = 0;

    for(int j = 0; j <= 6; j++){
        for( int k = j; k <= 6; k++){

            pecas[i].numero1 = j;
            pecas[i].numero2 = k;
            i++;
        }
    }
}

void imprimirPecas(PECA* pecas){

    for(int i = 0; i < TOTAL_PECAS; i++){
        printf("\nstatus %d\t: %d | %d \n", pecas[i].status, pecas[i].numero1, pecas[i].numero2);
    }
}

void embaralharPecas(PECA* pecas){

    srand(time(NULL)); //estabelecendo a semente do rand()
    int posicaoSorteada;
    PECA variavelAuxiliar; //variavel temporaria 

    for(int i = 0; i < TOTAL_PECAS; i++){

        posicaoSorteada = rand() % 28;

        //armazenando a peca localizada na posicao sorteada na variavel auxiliar
        variavelAuxiliar.numero1 = pecas[posicaoSorteada].numero1;
        variavelAuxiliar.numero2 = pecas[posicaoSorteada].numero2;

        //passando a peca localizada na posicao i para a posicao sorteada
        pecas[posicaoSorteada].numero1 = pecas[i].numero1;
        pecas[posicaoSorteada].numero2 = pecas[i].numero2;

        //passando a variavel auxiliar para a peca na posicao i
        pecas[i].numero1 = variavelAuxiliar.numero1;
        pecas[i].numero2 = variavelAuxiliar.numero2;

    }
}

void distribuirPecas(PECA* pecas){

    for(int i = 0; i < TOTAL_PECAS; i++){
        if (i < 7){
            pecas[i].status = JOGADOR_1;
        } else if (i < 14){
                pecas[i].status = JOGADOR_2;
            }else {
                pecas[i].status = PILHA;
            }
    }
}

void escolherPrimeiroJogador(PECA* pecas){

    PECA primeiraJogada;

    int pecaMaiorJogador1;
    int pecaMaiorJogador2;

    PECA jogador1[7];
    PECA jogador2[7];

    //adiciona as pecas dos respectivos jogadores nos arrays criados acima
    for(int i = 0; i < 14; i++){
        if (i < 7){
            pecas[i].numero1 = jogador1[i].numero1;
            pecas[i].numero2 = jogador1[i].numero2;
        } else {
            pecas[i].numero1 = jogador2[i-7].numero1;
            pecas[i].numero2 = jogador2[i-7].numero2;
            }
    }

    int posicaoPecaMaiorJogador1 = encontrarPecaMaior(jogador1, pecas);
    pecaMaiorJogador1 = jogador1[posicaoPecaMaiorJogador1].numero1;

    int posicaoPecaMaiorJogador2 = encontrarPecaMaior(jogador2, pecas);
    pecaMaiorJogador2 = jogador2[posicaoPecaMaiorJogador2].numero1;

    if(pecaMaiorJogador1 > pecaMaiorJogador2){
        pecas[posicaoPecaMaiorJogador1].status = MESA;    
    }
    else 
        pecas[posicaoPecaMaiorJogador2 + 7].status = MESA;    
    

}

int encontrarPecaMaior(PECA* jogador, PECA* pecas){

    int posicaoPecaMaior;
    int pecaMaior = -1;

    for(int i = 0; i < 7; i++){
        if(jogador[i].numero1 == jogador[i].numero2){
            if (jogador[i].numero1 > pecaMaior)
                pecaMaior = jogador[i].numero1;
                posicaoPecaMaior = i;
        }
    }

    if (pecaMaior == -1){
        return 
    }

    return posicaoPecaMaior;
}

void imprimirPecasjogador(PECA* pecas, PECA* mesa){

    imprimirMostrarPecas();
    int qtdPecas = 0;

    for(int i = 0; i < TOTAL_PECAS; i++){
        if(pecas[i].status == mesa->jogadorAtual){
            printf("[ %d | %d ]\t ", pecas[i].numero1, pecas[i].numero2);
            qtdPecas++;
        }
    } printf("\n");
    
    for(int j = 0; j <= qtdPecas-1; j++){
        printf("    (%d)\t\t", j+1);
    }printf("\n");

}

void imprimirMesa(PECA* mesa){

    imprimirMostrarMesa();

    for(int i = 0; i < TOTAL_PECAS; i++){
            printf("[ %d | %d ]\t ", mesa[i].numero1, mesa[i].numero2);
        
    }
}

void trocarJogador(PECA* mesa){

    if(mesa->jogadorAtual == JOGADOR_1)
        mesa->jogadorAtual = JOGADOR_2;
    else
        mesa->jogadorAtual = JOGADOR_1;

}

int comprarPeca(PECA* pecas, PECA* mesa){

    for(int i = 0; i < TOTAL_PECAS; i++){

        if(pecas[i].status == PILHA){
            if(mesa->jogadorAtual == JOGADOR_1){
                printf("\n Voce comprou essa peca : [ %d | %d ]\n ", pecas[i].numero1, pecas[i].numero2);
                pecas[i].status = JOGADOR_1;
                return 1;
            }
            else{
                pecas[i].status = JOGADOR_2;
                return 1;
            }
        }
    }
}

int escolherPeca(PECA* pecas, PECA* mesa){

    int pecaEscolhida;
    
    imprimirPecasjogador(pecas,mesa);
    imprimirEscolherPeca();
    scanf("%d", &pecaEscolhida);

    return pecaEscolhida;

}

void jogarPrimeiraPeca(PECA* pecas, PECA* mesa){

    int peca = escolherPeca(pecas,mesa);
    
    //if(??????)




}

void jogarPeca(PECA* pecas, PECA* mesa){

    imprimirMostrarMesa();
    imprimirMesa(pecas);

    escolherPeca(pecas,mesa);

    //verificarValidadeDaJogada()

}

/* A FAZER:

* refazer toda a primeira jogada
* 

*/
