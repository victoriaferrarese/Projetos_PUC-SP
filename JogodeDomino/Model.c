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
        printf("peca %d\t: %d | %d \n", i, pecas[i].numero1, pecas[i].numero2);
    }
}

void embaralharPecas(PECA* pecas){

    srand(time(NULL)); //estabelecendo a semente do rand()
    int posicaoSorteada;
    PECA variavelAuxiliar; //variavel temporaria 

    for(int i = 0; i < 28; i++){

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

    for(int i = 0; i < 28; i++){
        if (i < 7){
            pecas[i].status = JOGADOR_1;
        } else if (i < 14){
                pecas[i].status = JOGADOR_2;
            }else {
                pecas[i].status = PILHA;
            }
    }
}

int escolherPrimeiroJogador(){

    int primeiroJogador;

    do{

        imprimirEscolherPrimeiroJogador();
        scanf("%d", &primeiroJogador);

    }while(primeiroJogador > 2 || primeiroJogador < 1);


    return primeiroJogador;    

}

void imprimirPecasjogador(PECA* pecas, int jogador){

    imprimirMostrarPecas();

    if(jogador == 1){
        for(int i = 0; i < 7; i++){
            printf("[ %d | %d ]\t ", pecas[i].numero1, pecas[i].numero2);
        }
    }
    else {
        for(int i = 7; i < 14; i++){
            printf("[ %d | %d ]\t ", pecas[i].numero1, pecas[i].numero2);
        }
    }
}

/*void comprarPeca(PECA* pecas, PECAS_MESA* Mesa, int jogador){

   // PECA pecaParaComprar = peca




}*/

/* A FAZER:

*  Permitir jogada (controller.c -> menuJogadorVsJogador -> case 1).
* atribuir valor à variavel jogador atual no struct mesa
*/
