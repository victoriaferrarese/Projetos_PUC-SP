#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

int opcaoSelecionadaMenuPrincipal(){ //retorna a opcao selecionada do menu principal

    int opcaoSelecionadaPrincipal;
    scanf("%d",&opcaoSelecionadaPrincipal);
    return opcaoSelecionadaPrincipal;
}

int opcaoSelecionadaMenuJogar(){//retorna a opcao selecionada do menu Jogar

    int opcaoSelecionadaJogar;
    scanf("%d",&opcaoSelecionadaJogar);
    return opcaoSelecionadaJogar;
}

int opcaoSelecionadaMenuPartida(){ //retorna a opcao selecionada do Menu Partida

    int opcaoSelecionadaPartida;
    scanf("%d",&opcaoSelecionadaPartida);
    return opcaoSelecionadaPartida;
}

void gerarPecas(pecaInfo pecas[]){

    int i =0;

    for(int j = 0; j <= 6; j++) //primeiro numero da peca
    {
        for (int k = j; k <= 6; k++) //segundo numero da peca
        {
            pecas[i].numero1 = j;
            pecas[i].numero2 = k;
            pecas[i].posicao = i;

            i++;//contador de pecas
        }
    }
}
void embaralharPecas(pecaInfo pecas[]){

    int posicaoTemporaria;
    int numeroSorteado;

    srand(time(NULL));//gera um valor inicial para a funcao rand(),que nunca se repete (baseado no rel�gio do sistema)

    for (int i = 0;i < 28; i++)
    {

        numeroSorteado = rand()%27; //gera um numero aleatorio entre 0 e 27.

        posicaoTemporaria = pecas[i].posicao; //posicaoTemporaria recebe o valor da posicao [i]

        // a peca da posicao sorteada e a peca da posicao [i] trocam de valores entre si
        pecas[i].posicao = pecas[numeroSorteado].posicao;
        pecas[numeroSorteado].posicao = posicaoTemporaria;

    }
}

void distribuirPecas(pecaInfo pecas[]){

    for (int i = 0; i < 14; i++)
    {
        pecas[(pecas[i].posicao)].status = J1;
        pecas[(pecas[i].posicao+7)].status = J2;
    }
    
    for (int j = 14; j < 28; j++)
    {
        pecas[(pecas[j].posicao)].status = PILHA;
    }
    
}

void iniciarJogo(pecaInfo pecas[]){

    gerarPecas(pecas);
    embaralharPecas(pecas);
    //distribuirPecas(); 

}

void desembaralharPecas(pecaInfo pecas[]){

    for(int j = 0; j < 28; j++)
    {
        pecas[j].posicao = j;
    }
}



