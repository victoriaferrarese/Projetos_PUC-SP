#define TOTAL_PECAS 28
#define MESA 'm'
#define PILHA 'p'
#define JOGADOR_1 1
#define JOGADOR_2 2

#ifndef _PECA_
#define _PECA_

struct pecaInfo{

    int numero1;
    int numero2;
    char status; //indica se a peca esta na mesa, com jogador1, com o jogador2 ou na pilha de compra

};
typedef struct pecaInfo PECA;

struct Mesa{

    int lado1; 
    int lado2;
    int jogadorAtual;

};
typedef struct Mesa PECA_MESA;

#endif

void iniciarJogo(PECA* pecas);
void inicializarPecas(PECA* pecas);
void imprimirPecas(PECA* pecas);
void embaralharPecas(PECA* pecas);
void distribuirPecas(PECA* pecas);
int escolherPrimeiroJogador();
void imprimirPecasjogador(PECA* pecas, int jogador);