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
        for(int j = 0; j < MAX; j++){
            m->matriz[i][j] = VAZIO;
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

            if (m->matriz[i][j] == VAZIO)
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
            m->matriz[linha][coluna] = SER_VIVO;
            i++;
        }else
            imprimirPosicaoInvalida();

    }while(i <= quantidade);
}

//simula a proxima geracao de seres vivos no mundo auxiliar. Em seguida passa o mundo auxiliar para o mundo m 
void simularGeracao(MUNDO* m, MUNDO* auxiliar){

    inicializarMundoAuxiliar(m, auxiliar);
    percorrerMundo(m, auxiliar);
    
    //o mundo m recebe a geracao atualizada dos seres vivos
    /*for(int i = 0; i < m->linhas; i ++){
        for(int j = 0; j < m->colunas; j++){
                auxiliar->matriz[i][j] = m->matriz[i][j];
        }
    }*/
}

//preenchendo o mundo auxiliar com os espacos vazios assim como o mundo m 
void inicializarMundoAuxiliar(MUNDO* auxiliar, MUNDO* m){

    auxiliar->linhas = m->linhas;
    auxiliar->colunas = m->colunas;
    
    inicializarMundo(auxiliar);

}

/*
//copiando o mundo m em outro mundo
void inicializarMundoAuxiliar(MUNDO* destino){
    //printf("\ninicializado\n");
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

 
    //fazendo uma copia do mundo origem e mandando para o mundo destino
    for(int i = 0; i < destino->linhas; i ++){
        for(int j = 0; j < destino->colunas; j++){
                destino->matriz[i][j] = origem->matriz[i][j];
        }
    }
   // printf("\nmundo auxiliar criado:\n");
    
}*/

//lendo o mundo m e atualizando o mundo auxiliar com a proxima geracao 
void percorrerMundo(MUNDO* m, MUNDO* auxiliar){
    
    int vizinhos = 0;

    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            printf("percorrendo: [%d %d]");
            vizinhos = contarVizinhos(m, i, j);
            atualizarGeracao(m, auxiliar, vizinhos, i, j);
        }
    }

}

//Contando a quantidade de seres vivos vizinhos (verificando todas as 8 celulas vizinhas do ser vivo )
int contarVizinhos(MUNDO* m, int x, int y){
    
    int contVizinhos = 0;

    if(posicaoValida(m, x-1, y-1)){
        if(m->matriz[x-1][y-1] == SER_VIVO)
            contVizinhos++;
    }
     if(posicaoValida(m, x-1, y)){
        if(m->matriz[x-1][y] == SER_VIVO)
            contVizinhos++;
    }
     if(posicaoValida(m, x-1, y+1)){
        if(m->matriz[x-1][y+1] == SER_VIVO)
            contVizinhos++;
    }
     if(posicaoValida(m, x, y-1)){
        if(m->matriz[x][y-1] == SER_VIVO)
            contVizinhos++;
    }
     if(posicaoValida(m, x, y+1)){
        if(m->matriz[x][y+1] == SER_VIVO)
            contVizinhos++;
    }
    if(posicaoValida(m, x+1, y-1)){
        if(m->matriz[x+1][y-1] == SER_VIVO)
            contVizinhos++;
    }
    if(posicaoValida(m, x+1, y)){
        if(m->matriz[x+1][y] == SER_VIVO)
            contVizinhos++;
    }
    if(posicaoValida(m, x+1, y+1)){
        if(m->matriz[x+1][y+1] == SER_VIVO)
            contVizinhos++;
    }

    return contVizinhos;
}

//atualizando o mundo auxiliar com a proxima geracao de seres vivos 
void atualizarGeracao(MUNDO* m, MUNDO* auxiliar, int vizinhos, int x, int y){
    
    //Reproducao: um ser vivo nasce numa celula vazia se essa celular vazia tiver exatamente 3 vizinhos.
    if(m->matriz[x][y] == VAZIO){
        if(vizinhos == 3)
            auxiliar->matriz[x][y] = SER_VIVO;
    }

    //Sobrevivencia: Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geracao seguinte.
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos == 2 || vizinhos == 3 )
            auxiliar->matriz[x][y] = SER_VIVO;
    }

    //Morte por falta de comida: Um ser vivo com 4 ou mais vizinhos morre de fome.
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos >= 4)
            auxiliar->matriz[x][y] = VAZIO;
    }
    
    //Morte por solidao: Um ser vivo com 0 ou 1 vizinho morre de solidao.
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos == 0 || vizinhos == 1)
            auxiliar->matriz[x][y] = VAZIO;
    }
}

/* A FAZER:
- Resolver bug : mundo nao e alterado apos a geracao ser simulada 
- 
- 
*/


