#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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

void imprimirPecasjogador(PECA* pecas, INFO_GERAL* partida){

    printf("\n\t\t\t\t\tEssas sao as suas pecas jogador %d:\n\n ", partida->jogadorAtual);
    int qtdPecas = 0;

    for(int i = 0; i < TOTAL_PECAS; i++){
        if(pecas[i].status == partida->jogadorAtual){
            printf("[ %d | %d ]\t ", pecas[i].numero1, pecas[i].numero2);
            qtdPecas++;
        }
    } printf("\n");
    
    for(int j = 0; j <= qtdPecas-1; j++){
        printf("    (%d)\t\t", j);
    }printf("\n");

}

void imprimirMesa(PECA* mesa, INFO_GERAL* partida){

    imprimirMostrarMesa();

    //for(int i = 0; i < partida->contMesa; i++){

        printf("[ %d | %d ]\t ", mesa[0].numero1, mesa[0].numero2);
    //}
}

void trocarJogador(INFO_GERAL* partida){

    if(partida->jogadorAtual == JOGADOR_1)
        partida->jogadorAtual = JOGADOR_2;
    else
        partida->jogadorAtual = JOGADOR_1;

}

int comprarPeca(PECA* pecas, INFO_GERAL* partida){

    for(int i = 0; i < TOTAL_PECAS; i++){

        if(pecas[i].status == PILHA){
            if(partida->jogadorAtual == JOGADOR_1){
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
void encontrarPrimeiroJogador(PECA* pecas, INFO_GERAL* partida, PECA* mesa){

    
    int posicaoPecaMaiorJ1 = encontrarPecaMaiorJogador1(pecas);
    int posicaoPecaMaiorJ2 = encontrarPecaMaiorJogador2(pecas);
    
    //caso nenhum dos jogadores tenha uma peca com dois lados iguais (jogadores escolhem quem comeca a partida)
    if(posicaoPecaMaiorJ1 == -1 && posicaoPecaMaiorJ2 == -1){
        
        escolherPrimeiroJogador(pecas, partida);
        jogarPrimeiraPeca(pecas, partida, mesa);
    }

    //caso o jogador 1 seja o unico que tenha uma peca com dois lados iguais (jogador 1 comeca a partida)
    else if(posicaoPecaMaiorJ1 != -1 && posicaoPecaMaiorJ2 == -1){
        
        partida->jogadorAtual = JOGADOR_1;
        imprimirJogador1Comeca();
        jogarPrimeiraPeca(pecas, partida, mesa);
    }

    //caso o jogador 2 seja o unico que tenha uma peca com dois lados iguais (jogador 2 comeca a partida)
    else if(posicaoPecaMaiorJ1 == -1 && posicaoPecaMaiorJ2 != -1){
       
        partida->jogadorAtual = JOGADOR_2;
        imprimirJogador2Comeca();
        jogarPrimeiraPeca(pecas, partida, mesa);

    }

    //caso a peca do jogador 1 seja maior que a peca do jogador 2 (jogador 1 comeca)
    else if(pecas[posicaoPecaMaiorJ1].numero1 > pecas[posicaoPecaMaiorJ2].numero1 ){
        
        partida->jogadorAtual = JOGADOR_1;
        imprimirJogador1Comeca();
        jogarPrimeiraPeca(pecas, partida, mesa);
    }

    //caso a peca do jogador 2 seja maior que a peca do jogador 1 (jogador 2 comeca)
    else{
       
        partida->jogadorAtual = JOGADOR_2;
        imprimirJogador2Comeca();
        jogarPrimeiraPeca(pecas, partida, mesa);
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

void escolherPrimeiroJogador(PECA* pecas, INFO_GERAL* partida){

    int primeiroJogador;

    do{

        imprimirEscolherPrimeiroJogador();
        scanf("%d",&primeiroJogador);

    }while(primeiroJogador > 2 || primeiroJogador < 1);

    if(primeiroJogador == 1)
        partida->jogadorAtual = JOGADOR_1; 
    else
        partida->jogadorAtual = JOGADOR_2;
}

int escolherPeca(PECA* pecas, INFO_GERAL* partida){

    int pecaEscolhida;
    
    imprimirPecasjogador(pecas, partida);
    imprimirEscolherPeca();
    scanf("%d", &pecaEscolhida);

    return pecaEscolhida;

}

//criando um array para a mao de cada um dos jogadores 
void jogarPrimeiraPeca(PECA* pecas, INFO_GERAL* partida, PECA* mesa){

    PECA maoJogador[TOTAL_PECAS];
    int contPecas = 0;

    if(partida->jogadorAtual == JOGADOR_1){
        for(int i = 0; i < TOTAL_PECAS; i++){
            if (pecas[i].status == JOGADOR_1){
                maoJogador[contPecas].numero1 = pecas[i].numero1;
                maoJogador[contPecas].numero2 = pecas[i].numero2;
                contPecas++;
            }
        }
        
    }else if(partida->jogadorAtual == JOGADOR_2){
        for(int i = 0; i < TOTAL_PECAS; i++){
            if(pecas[i].status == JOGADOR_2){
                
                maoJogador[contPecas].numero1 = pecas[i].numero1;
                maoJogador[contPecas].numero2 = pecas[i].numero2;
                contPecas++;
            }    
        }
    }
    
    atualizarMesaPrimeiraJogada(pecas, mesa, partida, maoJogador, contPecas);
}

void atualizarMesaPrimeiraJogada(PECA* pecas, PECA* mesa, INFO_GERAL* partida, PECA* maoJogador, int qtdPecas){
    
    //recebendo o local (no array PECA maoJogador) da peca escolhida 
    int pecaSelecionada = escolherPeca(pecas,partida);

    for(int i = 0; i < TOTAL_PECAS; i++){
        //localizando a peca selecionada pelo jogador no array PECA pecas
        if (pecas[i].numero1 == maoJogador[pecaSelecionada].numero1 && pecas[i].numero2 == maoJogador[pecaSelecionada].numero2){

            //atualizando o status da peca jogada e o valor da variavel contMesa
            pecas[i].status = MESA;
            partida->contMesa++;

            //adicionando a peca jogada no array PECA mesa
            mesa[0].numero1 = pecas[i].numero1;
            mesa[0].numero2 = pecas[i].numero2;
            
            break;
        }
    }imprimirMesa(mesa, partida);
   
}

/*void jogarPeca(PECA* pecas, INFO_GERAL* partida){

    PECA* maoJogador[TOTAL_PECAS];
    int contPecas;

    if(partida->jogadorAtual == JOGADOR_1){
        for(int i = 0; i < TOTAL_PECAS; i++){
            if (pecas[i].status == JOGADOR_1){
                maoJogador[contPecas]->numero1 = pecas[i].numero1;
                maoJogador[contPecas]->numero2 = pecas[i].numero2;
                contPecas++;
            }
        }
        
    }else if(partida->jogadorAtual == JOGADOR_2){
        for(int i = 0; i < TOTAL_PECAS; i++){
            if(pecas[i].status == JOGADOR_2){
                
                maoJogador[contPecas]->numero1 = pecas[i].numero1;
                maoJogador[contPecas]->numero2 = pecas[i].numero2;
                contPecas++;
            }    
        }
    }

    atualiazarMesa(pecas, partida, maoJogador, contPecas);
}

void atualizarMesa(PECA* pecas, INFO_GERAL* partida, PECA* maoJogador, int qtdPecas){
    
    int pecaSelecionada = escolherPeca(pecas,partida);

    for(int i = 0; i < qtdPecas; i++){
        //achando a peca jogada pelo jogador no array pecas
        if (pecas[i].numero1 == maoJogador[pecaSelecionada].numero1 && pecas[i].numero2 == maoJogador[pecaSelecionada].numero2){
            
            if(pecas[i].numero1 == mesa-> lado1){ // *********************
                pecas[i].status = MESA;
                partida->contMesa++;
                //mesa->lado1 = maoJogador[pecaSelecionada].numero1;
                //mesa->lado2 = maoJogador[pecaSelecionada].numero2;
            }
            
        }
    }imprimirMesa(pecas);
   
}
*/

/* A FAZER:

* atualizar imprimir mesa
* 

*/
