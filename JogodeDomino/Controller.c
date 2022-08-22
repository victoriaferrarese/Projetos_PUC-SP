#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "Controller.h"
#include "View.h"

void interface(pecaInfo pecas[])
{
    int sentinela = 0;


    do{
        int opcao = imprimirMenu();

        switch(opcao){

            case 1:
                gerarPecas(pecas);
                break;

            case 2:
                imprimirPecas(pecas);
                break;

            case 3:
                embaralharPecas(pecas);
                imprimirPecasEmbaralhadas(pecas);
                break;

            case 4:
                desembaralharPecas(pecas);
                imprimirPecas(pecas);
                break;

            default:
                sentinela = 0;
                break;
        }

    }while(sentinela != 1);

}
