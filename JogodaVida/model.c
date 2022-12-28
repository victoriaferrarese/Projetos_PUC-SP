#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void receberTamanhoMundo(){
    int linhas;
    int colunas;

    printf("\nLinhas: ");
    scanf(" %d", linhas);

    printf("\nColunas: ");
    scanf(" %d", colunas);

   printf("\n %d %d", linhas, colunas);

}

