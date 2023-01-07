#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void menuPrincipal(MUNDO* m, MUNDO* auxiliar){

    int fimDeJogo = 0;

    imprimirAbertura();

    int menu = receberOpcao();

    do{
    switch (menu){

        //Jogar
        case 1:

            menuJogar(m, auxiliar);
            break;

        //
        case 2: 


            break;

        //
        case 3:

           
        default:

            imprimirOpcaoInvalida();
            break;

    }
    
    imprimirMenuPrincipal();
    menu = receberOpcao();

    }while(!fimDeJogo);
    
}

void menuJogar(MUNDO* m, MUNDO* auxiliar){

    imprimirMenuJogar();
    int menuJogar = receberOpcao();

    int geracoes = 0;
    int sair = 0;

    do{
    switch(menuJogar){

        //Definir Seres vivos
        case 1:

            do{

            receberTamanhoMundo(m);

            }while(m->linhas < MIN || m->linhas > MAX || m->colunas < MIN || m->colunas > MAX);

            inicializarMundo(m);
            definirSeresVivos(m);
            imprimirMundo(m);

            break;
        
        //Simular geracoes
        case 2 :

            geracoes = receberQtdGeracoes();
            int i = 0;
    
            do{

            simularGeracao(m, auxiliar, i);
            i++;

            }while(i < geracoes);

            break;


        //Limpar mundo
        case 3:

            inicializarMundo(m);
            imprimirMundo(auxiliar);

            break;
        
        //Sair
        case 4:

            menuPrincipal(m, auxiliar);
        
        default:

            imprimirOpcaoInvalida();
            break;

    }
    }while(!sair);

    imprimirMenuJogar();
    menuJogar = receberOpcao();

}