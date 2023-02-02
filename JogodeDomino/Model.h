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

struct partidaInfo{

    int contMesa;
    int jogadorAtual;
    int vencedor;

};
typedef struct partidaInfo INFO_GERAL;

#endif

void iniciarJogo(PECA* pecas);
void inicializarPecas(PECA* pecas);
void imprimirPecas(PECA* pecas);
void embaralharPecas(PECA* pecas);
void distribuirPecas(PECA* pecas);
void imprimirPecasjogador(PECA* pecas, INFO_GERAL* partida);
void imprimirMesa(PECA* mesa, INFO_GERAL* partida);
void trocarJogador(INFO_GERAL* partida);
void comprarPeca(PECA* pecas, INFO_GERAL* partida);
void encontrarPrimeiroJogador(PECA* pecas, INFO_GERAL* partida, PECA* mesa);
int encontrarPecaMaiorJogador1(PECA* pecas);
int encontrarPecaMaiorJogador2(PECA* pecas);
void escolherPrimeiroJogador(PECA* pecas, INFO_GERAL* partida);
void imprimirescolherOpcaoMenu(INFO_GERAL* partida);
int escolherPeca(PECA* pecas, INFO_GERAL* partida);
void atualizarMesaPrimeiraJogada(PECA* pecas, PECA* mesa, INFO_GERAL* partida, PECA* maoJogador, int qtdPecas);
void jogarPrimeiraPeca(PECA* pecas, INFO_GERAL* partida, PECA* mesa);
void jogarPeca(PECA* pecas, INFO_GERAL* partida, PECA* mesa);
void atualizarMesa(PECA* pecas, PECA* mesa, INFO_GERAL* partida, PECA* maoJogador, int qtdPecas);
int JogadaInvalida(PECA* pecas, PECA* mesa, int posicaoPecaJogada, int mesaLado1, int mesaLado2);
void organizarMesa(PECA* pecas, PECA* mesa, INFO_GERAL* partida, int posicaoPecaJogada, int mesaLado1, int mesaLado2);
void inverterNumerosPeca(PECA* pecas, int posicao);
void adicionarPecaNoLado1DaMesa(PECA* pecas, PECA* mesa, INFO_GERAL* partida, int posicao);
void adicionarPecaNoLado2DaMesa(PECA* pecas, PECA* mesa, INFO_GERAL* partida, int posicao);
int fimDeJogo(PECA* pecas, PECA* mesa, INFO_GERAL* partida);
int jogadorSemPecas(PECA* pecas, INFO_GERAL* partida);
int mesaTrancada(PECA* pecas, PECA* mesa, INFO_GERAL* partida);
void contarPontosJogadores(PECA* pecas);
void salvarPartida(PECA* pecas, PECA* mesa, INFO_GERAL* partida);
void sairPartida(PECA* pecas, PECA* mesa, INFO_GERAL* partida);
void carregarPartidaSalva(PECA* pecas, PECA* mesa, INFO_GERAL* partida);


//void jogarPeca(PECA* pecas, INFO_GERAL* partida);
//void atualizarMesa(PECA* pecas, INFO_GERAL* partida, PECA* maoJogador, int qtdPecas);