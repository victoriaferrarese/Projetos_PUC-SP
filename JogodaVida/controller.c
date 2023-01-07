#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void menu(){

    int fimDeJogo = 0;

    imprimirAbertura();

    MUNDO m;
    MUNDO auxiliar;

    int menu = receberOpcao();

    int geracoes = 0;

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
            imprimirMundo(&auxiliar);
            break;

        //simular 1 geracao
        case 3:

            geracoes = receberQtdGeracoes();
            int i = 0;
    
            do{

            simularGeracao(&m, &auxiliar, i);
            i++;

            }while(i < geracoes);

            break;

        default:

            imprimirPosicaoInvalida();
            break;
    }
    
    menu = receberOpcao();

    }while(!fimDeJogo);
    
}