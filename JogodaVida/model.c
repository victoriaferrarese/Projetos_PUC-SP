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

void inicializarMundoAuxiliar(MUNDO* origem, MUNDO* destino){

    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    //fazendo uma copia do mundo origem e mandando para o mundo destino
    for(int i = 0; i < origem->linhas; i ++){
        for(int j = 0; j < origem->colunas; j++){
                destino->matriz[i][j] = origem->matriz[i][j];
        }
    }
}

void percorrerMundo(MUNDO* m, MUNDO* auxiliar){

    int linha;
    int coluna;
    int vizinhos;

    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            linha = i;
            coluna = j;
            vizinhos = contarVizinhos(m, linha,coluna);
            criarMundoAuxiliar(m, auxiliar, vizinhos, linha, coluna);
        }
    }

}
//Contando a quantidade de seres vivos vizinhos 
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

//
void criarMundoAuxiliar(MUNDO* m, MUNDO* auxiliar, int vizinhos, int x, int y){

    if(m->matriz[x][y] == VAZIO){
        if(vizinhos == 3)
            auxiliar->matriz[x][y] = SER_VIVO;
    }
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos == 2 || vizinhos == 3 )
            auxiliar->matriz[x][y] = SER_VIVO;
    }
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos >= 4)
            auxiliar->matriz[x][y] = VAZIO;
    }
    if(m->matriz[x][y] == SER_VIVO){
        if(vizinhos == 0 || vizinhos == 1)
            auxiliar->matriz[x][y] = VAZIO;
    }
}

void simularGeracao(MUNDO* m, MUNDO* auxiliar){

    percorrerMundo(m, auxiliar);

    for(int i = 0; i < m->linhas; i ++){
        for(int j = 0; j < m->colunas; j++){
                auxiliar->matriz[i][j] = m->matriz[i][j];
        }
    }

}
/* A FAZER:
- Criar um mapa auxiliar para atualizar a cada geracao nova
- terminar as funcoes percorrerMundo, contarVizinhos e simularGeracao
- declarar simularGeracao
*/


