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



void imprimirPecasjogador(PECA* pecas, PECAS_MESA* mesa){

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

void trocarJogador( PECAS_MESA* mesa){

    if(mesa->jogadorAtual == JOGADOR_1)
        mesa->jogadorAtual = JOGADOR_2;
    else
        mesa->jogadorAtual = JOGADOR_1;

}

int comprarPeca(PECA* pecas, PECAS_MESA* mesa){

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

int encontrarPrimeiroJogador(PECA* pecas, PECA* mesa){

    int posicaoPecaMaiorJ1 = encontrarPecaMaiorJogador1(pecas);
    int posicaoPecaMaiorJ2 = encontrarPecaMaiorJogador2(pecas);
    
    if(posicaoPecaMaiorJ1 == -1 && posicaoPecaMaiorJ2 == -1){
        escolherPrimeiroJogador(pecas, mesa);
        jogarPrimeiraPeca(pecas, mesa); //*******************************************
    }
    else if(posicaoPecaMaiorJ1 != -1 && posicaoPecaMaiorJ2 == -1){
        //jogador 1 joga
    }
    else if(posicaoPecaMaiorJ1 == -1 && posicaoPecaMaiorJ2 != -1){
        //jogador 2 joga
    }
    else if(pecas[posicaoPecaMaiorJ1].numero1 > pecas[posicaoPecaMaiorJ2].numero1 ){
        //jogador 1 joga
    }
    else{
        //jogador 2 joga
    }
}

int encontrarPecaMaiorJogador1(PECA* pecas){

    int posicaoPecaMaior;
    int pecaMaior = -1;

    for(int i = 0; i < 7; i++){
        if(pecas[i].numero1 == pecas[i].numero2){
            if (pecas[i].numero1 > pecaMaior)
                pecaMaior = pecas[i].numero1;
                posicaoPecaMaior = i;
        }
    }
    if(pecaMaior == -1){
        posicaoPecaMaior = -1;
    }

    return posicaoPecaMaior;
} 

int encontrarPecaMaiorJogador2(PECA* pecas){

    int posicaoPecaMaior;
    int pecaMaior = -1;

    for(int i = 7; i < 14; i++){
        if(pecas[i].numero1 == pecas[i].numero2){
            if (pecas[i].numero1 > pecaMaior)
                pecaMaior = pecas[i].numero1;
                posicaoPecaMaior = i;
        }
    }
    if(pecaMaior == -1){
        posicaoPecaMaior = -1;
    }

    return posicaoPecaMaior;
} 

void escolherPrimeiroJogador(PECA* pecas, PECAS_MESA* mesa){

    int primeiroJogador;

    do{

        imprimirEscolherPrimeiroJogador();
        scanf("%d",&primeiroJogador);

    }while(primeiroJogador > 2 || primeiroJogador < 1);

    if(primeiroJogador == 1)
        mesa->jogadorAtual = JOGADOR_1; 
    else
        mesa->jogadorAtual = JOGADOR_2;
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
