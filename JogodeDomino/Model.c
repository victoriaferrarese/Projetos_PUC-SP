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

    printf("\n");
    imprimirMostrarMesa();

    for(int i = 0; i < partida->contMesa; i++){
        printf("[ %d | %d ]\t ", mesa[i].numero1, mesa[i].numero2);
    }
    printf("\n");
}

void trocarJogador(INFO_GERAL* partida){

    if(partida->jogadorAtual == JOGADOR_1)
        partida->jogadorAtual = JOGADOR_2;
    else
        partida->jogadorAtual = JOGADOR_1;

}

void comprarPeca(PECA* pecas, INFO_GERAL* partida){

    for(int i = 0; i < TOTAL_PECAS; i++){

        if(pecas[i].status == PILHA){
            if(partida->jogadorAtual == JOGADOR_1){
                printf("\n Voce comprou essa peca : [ %d | %d ]\n ", pecas[i].numero1, pecas[i].numero2);
                pecas[i].status = JOGADOR_1;
                break;
            }
            else
                pecas[i].status = JOGADOR_2;
                break;
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

void imprimirescolherOpcaoMenu(INFO_GERAL* partida){

    printf("\n\nO que deseja fazer jogador %d?\n", partida->jogadorAtual);
}


int escolherPeca(PECA* pecas, INFO_GERAL* partida){

    int pecaEscolhida;
    
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
    
    imprimirPecasjogador(pecas, partida);

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
    } 
}

void jogarPeca(PECA* pecas, INFO_GERAL* partida, PECA* mesa){

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
    atualizarMesa(pecas, mesa, partida, maoJogador, contPecas);
}

void atualizarMesa(PECA* pecas, PECA* mesa, INFO_GERAL* partida, PECA* maoJogador, int qtdPecas){
    
    //armazenando os numeros correspondentes as duas extremidades da mesa 
    int mesaLado1 = mesa[0].numero1;
    int mesaLado2 = mesa[partida->contMesa - 1].numero2;

    int pecaSelecionada = escolherPeca(pecas,partida);
//***********************************
    if(!JogadaInvalida(maoJogador, mesa, pecaSelecionada, mesaLado1, mesaLado2)){
        for(int i = 0; i < TOTAL_PECAS; i++){
            //localizando a peca selecionada pelo jogador no array PECA pecas
            if (pecas[i].numero1 == maoJogador[pecaSelecionada].numero1 && pecas[i].numero2 == maoJogador[pecaSelecionada].numero2){
            printf("peca escolhida localizada no array pecas, posicao: %d\n", i);
            organizarMesa(pecas, mesa, partida, i, mesaLado1, mesaLado2); //organizar o array mesa
            //atualizar status da peca jogada
            pecas[i].status = MESA;

            }  
        }
    }
    else{
        imprimirPecaInvalida();
        jogarPeca(pecas, partida, mesa);

    }
}

int JogadaInvalida(PECA* maoJogador, PECA* mesa, int posicaoPecaJogada, int mesaLado1, int mesaLado2){

    //caso a peca jogada nao tenha o mesmo numero de nenhuma das extremidades da mesa a funcao retorna verdadeira
    return maoJogador[posicaoPecaJogada].numero1 != mesaLado1 && maoJogador[posicaoPecaJogada].numero1 != mesaLado2 && maoJogador[posicaoPecaJogada].numero2 != mesaLado1 && maoJogador[posicaoPecaJogada].numero2 != mesaLado2;

}

void organizarMesa(PECA* pecas, PECA* mesa, INFO_GERAL* partida, int posicaoPecaJogada, int mesaLado1, int mesaLado2){

    //caso o numero 1 da peca jogada seja igual ao lado 1 da mesa
    if(pecas[posicaoPecaJogada].numero1 == mesaLado1){
        inverterNumerosPeca(pecas, posicaoPecaJogada);
        adicionarPecaNoLado1DaMesa(pecas, mesa, partida, posicaoPecaJogada);
    }

    //caso o numero 1 da peca jogada seja igual ao lado 2 da mesa
    else if(pecas[posicaoPecaJogada].numero1 == mesaLado2){
        adicionarPecaNoLado2DaMesa(pecas, mesa, partida, posicaoPecaJogada);
    }

    //caso o numero 2 da peca jogada seja igual ao lado 1 da mesa
    else if(pecas[posicaoPecaJogada].numero2 == mesaLado1){
        adicionarPecaNoLado1DaMesa(pecas, mesa,partida, posicaoPecaJogada);

    }

    //caso o numero 2 da peca jogada seja igual ao lado 2 da mesa
    else{
        inverterNumerosPeca(pecas, posicaoPecaJogada);
        adicionarPecaNoLado2DaMesa(pecas, mesa, partida, posicaoPecaJogada);

    }
}

void inverterNumerosPeca(PECA* pecas, int posicao){
    printf("antes de inverter : [%d | %d]\n", pecas[posicao].numero1, pecas[posicao].numero2);
    
    int auxiliar = pecas[posicao].numero1;
    pecas[posicao].numero1 = pecas[posicao].numero2;
    pecas[posicao].numero2 = auxiliar;

    printf("depois de inverter : [%d | %d]\n", pecas[posicao].numero1, pecas[posicao].numero2);

}

void adicionarPecaNoLado1DaMesa(PECA* pecas, PECA* mesa, INFO_GERAL* partida, int posicao){

    for(int i = partida->contMesa; i >= 0; i--){

        mesa[i+1].numero1 = mesa[i].numero1;
        mesa[i+1].numero2 = mesa[i].numero2;

    }

    mesa[0].numero1 = pecas[posicao].numero1;
    mesa[0].numero2 = pecas[posicao].numero2;

    partida->contMesa++;
}

void adicionarPecaNoLado2DaMesa(PECA* pecas, PECA* mesa, INFO_GERAL* partida, int posicao){

    mesa[partida->contMesa].numero1 = pecas[posicao].numero1;
    mesa[partida->contMesa].numero2 = pecas[posicao].numero2;

    partida->contMesa++;

}


/* A FAZER:

* atualizar imprimir mesa
*

*/
