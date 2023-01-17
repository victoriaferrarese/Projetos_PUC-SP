#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "Controller.h"
#include "View.h"

int main(){

    PECA pecas[TOTAL_PECAS];

    inicializarPecas(pecas);
    imprimirPecas(pecas);
    embaralharPecas(pecas);
    printf("\nEmbaralhadas: \n");
    imprimirPecas(pecas);
    
}


