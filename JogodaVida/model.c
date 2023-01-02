#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "view.h"
#include "controller.h"

//recebendo o tamanho da matriz mundo do usuario
void receberTamanhoMundo(MUNDO* m){

    printf("\nLinhas: ");
    scanf(" %d", &m->linhas);

    printf("\nColunas: ");
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




