#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "domino.h"

void gerarpecas(pecaInfo pecas[])
{

   for(int i = 0; i < 28; i++) //contador de peças
    {
        for(int j = 0; j <= 6; j++) //primeiro número da peça
        {
            for (int k = j; k <= 6; k++) //segundo número da peça
            {
                pecas[i].numero1 = j;
                pecas[i].numero2 = k;

                i++;

            }
        }
    }

}
void imprimirpecas(pecaInfo pecas[])
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

}
void embaralharpecas(pecaInfo pecas[], pecaInfo pecasembaralhadas[])
{
    srand(time(NULL)); //gera um valor inicial para a função rand(),que nunca se repete (baseado no relogio do sistema)

    for (int i = 0; i < 28; i++)
    {
        int numerosorteado = rand()%27; //gera um numero aleatorio entre 0 e 27.

    }
}
