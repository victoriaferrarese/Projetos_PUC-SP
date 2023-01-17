#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

void imprimirMenuInicial(){
    printf("\nMENU:\n");
    printf("[1] gerar/organizar pecas\n");
    printf("[2] embaralhar pecas\n");
}

void imprimirOpcaoInvalida(){
    printf("Opcao Invalida!!");
}