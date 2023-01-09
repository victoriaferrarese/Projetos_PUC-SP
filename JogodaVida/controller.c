#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void menuInicial(MUNDO* m, MUNDO* auxiliar){

    //int fimDeJogo = 0;

    imprimirAbertura();
    imprimirMenuInicial();
    int menu = receberOpcao();

    //do{
    switch (menu){

        //Criar novo mundo 
        case 1:

            do{

            receberTamanhoMundo(m);

            }while(m->linhas < MIN || m->linhas > MAX || m->colunas < MIN || m->colunas > MAX);

            criarMundo(m);
            menuJogar(m, auxiliar);
            break;

        //Carregar mundo salvo
        case 2: 


            break;

        default:

            imprimirOpcaoInvalida();
            break;

    }
    
    imprimirMenuInicial();
    menu = receberOpcao();

    //}while(!fimDeJogo);
    
}

void menuJogar(MUNDO* m, MUNDO* auxiliar){

    imprimirMenuJogar();
    int menuJogar = receberOpcao();

    int sair = 0;

    //do{
    switch(menuJogar){

        //Adicionar seres vivos
        case 1:

            menuAdicionarSerVivo(m, auxiliar);

            break;

        //Simular Geracoes
        case 2:

            menuSimularGeracao(m, auxiliar);
            
            break;
        
        //Limpar mundo
        case 3 :

            


        //Salvar mundo
        case 4:

            inicializarMundo(m);
            imprimirMundo(auxiliar);

            break;
        
        default:

            imprimirOpcaoInvalida();
            break;

    }

    imprimirMenuJogar();
    menuJogar = receberOpcao();

    //}while(!sair);

}
void menuAdicionarSerVivo(MUNDO* m, MUNDO* auxiliar){

    imprimirMenuAdicionarSerVivo();
    int opcaoAdicionarSerVivo = receberOpcao();

    switch (opcaoAdicionarSerVivo){

        //Adicionar seres vivos manualmente (um por um)
        case 1:

            definirSeresVivos(m);
            imprimirApresentarMundo();
            imprimirMundo(m);

            break;

        //Escolher padrao ja existente de seres vivos
        case 2: 


            break;

        default:

            imprimirOpcaoInvalida();
            break;

    }
    
    menuJogar(m, auxiliar);
}

void menuSimularGeracao(MUNDO* m, MUNDO* auxiliar){

    imprimirMenuSimularGeracao();
    int opcaoSimularGeracao = receberOpcao();

    float tempoSimulacao = 0.75;
    int geracoes = 0;

    switch (opcaoSimularGeracao){

        //Definir o tempo de simulacao das geracoes
        case 1:

            tempoSimulacao = receberVelocidadeDeSimulacao();
            menuSimularGeracao(m, auxiliar);

            break;

        //Simular geracoes automaticamente
        case 2:

            geracoes = receberQtdGeracoes();
            int i = 0;
    
            do{

            aplicarVelocidadeDeSimulacao(tempoSimulacao);
            simularGeracao(m, auxiliar, i);
            i++;

            }while(i < geracoes);

            break;

        //Simular geracoes manualmente
        case 3: 


            break;

        default:

            imprimirOpcaoInvalida();
            break;

    }
    
    menuJogar(m, auxiliar);
}