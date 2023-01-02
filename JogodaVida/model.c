#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "view.h"
#include "controller.h"

//recebendo o tamanho da matriz mundo do usuario
void receberTamanhoMundo(MUNDO* m){

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

    printf(" ");
    for(int k = 0; k < m->colunas; k++){
            printf(" %d ", k);
           
    }printf("\n");

    for(int i = 0; i < m->linhas; i++){
        printf("%d ", i);
        for(int j = 0; j < m->colunas; j++){
           printf("%d  ", m->matriz[i][j]);

        }printf("\n");
    }
}

void definirSeresVivos(MUNDO* m){

    int qtdSerVivo;
    escolherQtdSeresVivos();
    scanf("%d", &qtdSerVivo);

    definirPosicaoSeresVivos(m,qtdSerVivo);

}

int posicaoValida(MUNDO* m, int x, int y){
    return (x <= m->linhas && y <= m->colunas);
}

void definirPosicaoSeresVivos(MUNDO* m, int quantidade){

    escolherPosicaoSeresVivos();

    for(int i = 1; i < quantidade; i++){
        int linha;
        int coluna;

        printf("Ser Vivo %d:\n ", i);
        receberLinha();
        scanf("%d", &linha);
        receberColuna();
        scanf("%d", &coluna);

        if(posicaoValida(m, linha, coluna)) 
            m->matriz[linha][coluna] = 1;
        else
            imprimirPosicaoInvalida();
    }
}


