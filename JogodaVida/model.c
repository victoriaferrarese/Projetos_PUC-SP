#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "view.h"
#include "controller.h"

//recebendo a opcao selecionada do Menu
int receberOpcao(){
    
    imprimirMenu();
    int opcao;
    scanf(" %d", &opcao);
    return opcao;
}

//recebendo o tamanho da matriz mundo do usuario
void receberTamanhoMundo(MUNDO* m){

    escolherTamanhoMundo();

    receberLinha();
    scanf(" %d", &m->linhas);

    receberColuna();
    scanf(" %d", &m->colunas);

}

//preenchendo a matriz com zeros
void inicializarMundo(MUNDO* m){

    for(int i = 0; i < MAX; i++){
        for(int j = 1; j < MAX; j++){
            m->matriz[i][j] = 0;
        }
    }

}

void imprimirMundo(MUNDO* m){

    //numerando as colunas
    printf(" ");
    for(int k = 0; k < m->colunas; k++){
            printf("  %d ", k);
           
    }printf("\n");

    for(int i = 0; i < m->linhas; i++){
        printf("%d ", i); //numerando as linhas
        for(int j = 0; j < m->colunas; j++){

            if (m->matriz[i][j] == 0)
                printf("   ");
            else 
                printf("  * ");

        }printf("\n");
    }
}

//recebendo a qnt de seres vivos e executando a funcao definirPosicaoSeresVivos()
void definirSeresVivos(MUNDO* m){

    int qtdSerVivo;
    escolherQtdSeresVivos();
    scanf("%d", &qtdSerVivo);

    definirPosicaoSeresVivos(m, qtdSerVivo);

}

//verificando se a posicao desejada para inserir o ser vivo existe 
int posicaoValida(MUNDO* m, int x, int y){
    return (x <= m->linhas && y <= m->colunas);
}

//Colocando os seres vivos nas posicoes escolhidas
void definirPosicaoSeresVivos(MUNDO* m, int quantidade){

    escolherPosicaoSeresVivos();

    int i = 1;
    do{
        int linha;
        int coluna;

        printf("\nSer Vivo %d:\n", i);

        receberLinha();
        scanf("%d", &linha);
        receberColuna();
        scanf("%d", &coluna);
    
        if(posicaoValida(m, linha, coluna)){ 
            m->matriz[linha][coluna] = 1;
            i++;
        }else
            imprimirPosicaoInvalida();

    }while(i <= quantidade);
}


