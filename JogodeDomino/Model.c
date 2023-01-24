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
        printf("    (%d)\t\t", j);
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

//O primeiro jogador eh aquele que possui a maior peca que contem os dois numeros iguais
void encontrarPrimeiroJogador(PECA* pecas, PECAS_MESA* mesa){

    int posicaoPecaMaiorJ1 = encontrarPecaMaiorJogador1(pecas);
    int posicaoPecaMaiorJ2 = encontrarPecaMaiorJogador2(pecas);
    
    //caso nenhum dos jogadores tenha uma peca com dois lados iguais (jogadores escolhem quem comeca a partida)
    if(posicaoPecaMaiorJ1 == -1 && posicaoPecaMaiorJ2 == -1){
        escolherPrimeiroJogador(pecas, mesa);
        separarPecasJogadores(pecas, mesa);
    }

    //caso o jogador 1 seja o unico que tenha uma peca com dois lados iguais (jogador 1 comeca a partida)
    else if(posicaoPecaMaiorJ1 != -1 && posicaoPecaMaiorJ2 == -1){
        mesa->jogadorAtual = JOGADOR_1;
        separarPecasJogadores(pecas, mesa);
    }

    //caso o jogador 2 seja o unico que tenha uma peca com dois lados iguais (jogador 2 comeca a partida)
    else if(posicaoPecaMaiorJ1 == -1 && posicaoPecaMaiorJ2 != -1){
        mesa->jogadorAtual = JOGADOR_2;
        separarPecasJogadores(pecas, mesa);

    }

    //caso a peca do jogador 1 seja maior que a peca do jogador 2 (jogador 1 comeca)
    else if(pecas[posicaoPecaMaiorJ1].numero1 > pecas[posicaoPecaMaiorJ2].numero1 ){
        mesa->jogadorAtual = JOGADOR_1;
        separarPecasJogadores(pecas, mesa);
    }

    //caso a peca do jogador 2 seja maior que a peca do jogador 1 (jogador 2 comeca)
    else{
        mesa->jogadorAtual = JOGADOR_2;
        separarPecasJogadores(pecas, mesa);
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

int escolherPeca(PECA* pecas, PECAS_MESA* mesa){

    int pecaEscolhida;
    
    imprimirPecasjogador(pecas,mesa);
    imprimirEscolherPeca();
    scanf("%d", &pecaEscolhida);

    return pecaEscolhida;

}

//criando um array para a mao de cada um dos jogadores 
void separarPecasJogadores(PECA* pecas, PECAS_MESA* mesa){

    PECA maoJogador1[TOTAL_PECAS];
    PECA maoJogador2[TOTAL_PECAS];

    //contadores das posicoes do array de cada jogador
    int contJ1 = 0;
    int contJ2 = 0;

    for(int i = 0; i < TOTAL_PECAS; i ++){
        if (pecas[i].status == JOGADOR_1){
            pecas[i].numero1 = maoJogador1[contJ1].numero1;
            pecas[i].numero2 = maoJogador1[contJ1].numero2;
            contJ1++;
        }
        else if(pecas[i].status == JOGADOR_2){
            pecas[i].numero1 = maoJogador2[contJ2].numero1;
            pecas[i].numero2 = maoJogador2[contJ2].numero2;
            contJ2++;
        }    
    }

    if(mesa->jogadorAtual == JOGADOR_1)
        jogarPrimeiraPeca(pecas, mesa, maoJogador1);
    else 
        jogarPrimeiraPeca(pecas ,mesa, maoJogador2);
}

void jogarPrimeiraPeca(PECA* pecas, PECAS_MESA* mesa, PECA* maoJogador){
    
    int pecaSelecionada = escolherPeca(pecas,mesa);

    for(int i = 0; i < TOTAL_PECAS; i++){
        if (pecas[i].numero1 == maoJogador[pecaSelecionada].numero1 && pecas[i].numero2 == maoJogador[pecaSelecionada].numero2){
            pecas[i].status = MESA;
            mesa->contMesa = 1;
            mesa->lado1 = maoJogador[pecaSelecionada].numero1;
            mesa->lado2 = maoJogador[pecaSelecionada].numero2;
        }
    }

    imprimirMesa(pecas);
}

/*void jogarPeca(PECA* pecas, PECA* mesa){

    imprimirMostrarMesa();
    imprimirMesa(pecas);

    escolherPeca(pecas,mesa);

    //verificarValidadeDaJogada()

}*/

/* A FAZER:

* compilar e arrumar os erros (se existentes)
* 

*/
