#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

void inicializarPecas(PECA* pecas){
    
    int i = 0;

    for(int j = 0; j <= 6; j++){
        for( int k = j; k <= 6; k++){

            pecas[i].numero1 = j;
            pecas[i].numero2 = k;
             i++;

        }
       
    }
    
}

void imprimirPecas(PECA* pecas){

    for(int i = 0; i < TOTAL_PECAS; i++){
        printf("peca %d\t: %d | %d \n", i, pecas[i].numero1, pecas[i].numero2);
    }
}



