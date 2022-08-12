#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "domino.h"

void gerarpecas(pecaInfo pecas[])
{
    int i =0;

    for(int j = 0; j <= 6; j++) //primeiro número da peça
    {
        for (int k = j; k <= 6; k++) //segundo número da peça
        {
            pecas[i].numero1 = j;
            pecas[i].numero2 = k;
            pecas[i].posicao = i;

            i++;//contador de peças
        }
    }
}
void imprimirPecas(pecaInfo pecas[])
{
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
void embaralharPecas(pecaInfo pecas[])
{
    int posicaoTemporaria;
    int numeroSorteado;

    srand(time(NULL));//gera um valor inicial para a função rand(),que nunca se repete (baseado no relógio do sistema)

    for (int i = 0;i < 28; i++){

        numeroSorteado = rand()%27; //gera um numero aleatório entre 0 e 27.

        posicaoTemporaria = pecas[i].posicao; //posicaoTemporaria recebe o valor da posição [i]

        // a peça da posição sorteada e a peça da posição [i] trocam de valores entre si
        pecas[i].posicao = pecas[numeroSorteado].posicao;
        pecas[numeroSorteado].posicao = posicaoTemporaria;

    }
}

void imprimirPecasEmbaralhadas(pecaInfo pecas[])
{
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
