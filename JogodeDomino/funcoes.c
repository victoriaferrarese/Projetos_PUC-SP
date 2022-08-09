#include <stdio.h>
#include <stdlib.h>
#include "domino.h"

void gerarpecas(ladospeca pecas[])
{

   for(int i = 0; i < 28; i++) //contador de pecas
    {
        for(int j = 0; j <= 6; j++) //primeiro numero
        {
            for (int k = j; k <= 6; k++) //segundo numero
            {
                pecas[i].lado1 = j;
                pecas[i].lado2 = k;

                i++;

            }
        }
    }

}
void imprimirpecas(ladospeca pecas[])
{
    for(int contador = 0; contador < 28; contador++)
    {
        printf("%d  ->  %d | %d\n",contador+1, pecas[contador].lado1,pecas[contador].lado2);
    }

}
