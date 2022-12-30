#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void abertura(MUNDO* m){

    alocarMundo(m);
    iniciarMundo(m);

}

void receberTamanhoMundo(MUNDO* m){

    printf("\nLinhas: ");
    scanf(" %d", &m->linhas);

    printf("\nColunas: ");
    scanf(" %d", &m->colunas);

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

    
}



