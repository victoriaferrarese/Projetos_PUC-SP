#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "Controller.h"
#include "View.h"

int main(){

    PECA pecas[TOTAL_PECAS];
    PECA mesa[TOTAL_PECAS];

    INFO_GERAL partida[TOTAL_PECAS]; 

    menuInicial(pecas, partida, mesa);
}


/*
PECAS_MESA mesa -> PECA mesa


*/