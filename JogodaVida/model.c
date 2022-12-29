#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void receberTamanhoMundo(MUNDO* m){

    do{
    printf("\nLinhas: ");
    scanf(" %d", &m->linhas);

    printf("\nColunas: ");
    scanf(" %d", &m->colunas);

    }while(10>m->linhas>60 && 10>m->colunas>60);

}

void alocarMundo(MUNDO* m){
    
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * m->colunas);
    }
}

void liberarMundo(MUNDO* m){
    
    for(int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void iniciarMundo(MUNDO* m){

    for(int i = 0; i < m->colunas; i++){
        m->matriz[0][i] = i;
    }

     for(int j = 0; j < m->linhas; j++){
        m->matriz[j][0] = j;
    }
}



