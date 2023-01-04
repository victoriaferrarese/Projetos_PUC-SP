#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void menu(){

    int fimDeJogo = 0;

    imprimirAbertura();

    MUNDO m;

    int menu = receberOpcao();

    do{
    switch (menu){

        //Jogar
        case 1:

            do{

            receberTamanhoMundo(&m);

            }while(m.linhas < MIN || m.linhas > MAX || m.colunas < MIN || m.colunas > MAX);

            inicializarMundo(&m);
            definirSeresVivos(&m);
            imprimirMundo(&m);
            break;

        //Limpar mundo
        case 2: 

            inicializarMundo(&m);
            imprimirMundo(&m);
            break;
    
        default:

            opcaoInvalida();
            break;
    }
    
    menu = receberOpcao();

    }while(!fimDeJogo);
    
}