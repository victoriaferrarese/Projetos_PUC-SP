#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

int imprimirMenu(){

        int opcaoSelecionada;

        printf("Escolha a opcao desejada: \n[1] Gerar Pecas. \n[2] Imprimir Pecas \n[3] Embaralhar Pecas \n[4]Desembaralhar Pecas");
        scanf("%d", &opcaoSelecionada);

        return opcaoSelecionada;
}

void imprimirPecas(pecaInfo pecas[])
{
    printf("As pecas de Domin� s�o:\n");
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
