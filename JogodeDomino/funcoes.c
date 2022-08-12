#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "domino.h"

void gerarpecas(pecaInfo pecas[])
{
    int i =0;

    for(int j = 0; j <= 6; j++) //primeiro n�mero da pe�a
    {
        for (int k = j; k <= 6; k++) //segundo n�mero da pe�a
        {
            pecas[i].numero1 = j;
            pecas[i].numero2 = k;
            pecas[i].posicao = i;

            i++;//contador de pe�as
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

    srand(time(NULL));//gera um valor inicial para a fun��o rand(),que nunca se repete (baseado no rel�gio do sistema)

    for (int i = 0;i < 28; i++){

        numeroSorteado = rand()%27; //gera um numero aleat�rio entre 0 e 27.

        posicaoTemporaria = pecas[i].posicao; //posicaoTemporaria recebe o valor da posi��o [i]

        // a pe�a da posi��o sorteada e a pe�a da posi��o [i] trocam de valores entre si
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
