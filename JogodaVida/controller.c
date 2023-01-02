#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void menu(){

    MUNDO m;

    do{
        receberTamanhoMundo(&m);

    }while(m.linhas < MIN || m.linhas > MAX || m.colunas < MIN || m.colunas > MAX);

    inicializarMundo(&m);
    imprimirMundo(&m);
    definirSeresVivos(&m);
    
}