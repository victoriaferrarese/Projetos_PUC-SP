#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

void gerarPecas(pecaInfo pecas[])
{
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
void embaralharPecas(pecaInfo pecas[])
{
    int posicaoTemporaria;
    int numeroSorteado;

    srand(time(NULL));//gera um valor inicial para a funcao rand(),que nunca se repete (baseado no rel�gio do sistema)

    for (int i = 0;i < 28; i++)
    {

        numeroSorteado = rand()%27; //gera um numero aleat�rio entre 0 e 27.

        posicaoTemporaria = pecas[i].posicao; //posicaoTemporaria recebe o valor da posi��o [i]

        // a pe�a da posi��o sorteada e a pe�a da posi��o [i] trocam de valores entre si
        pecas[i].posicao = pecas[numeroSorteado].posicao;
        pecas[numeroSorteado].posicao = posicaoTemporaria;

    }
}

void desembaralharPecas(pecaInfo pecas[])
{
    for(int j = 0; j < 28; j++)
    {
        pecas[j].posicao = j;
    }

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
}

