#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Model.h"
#include "View.h"
#include "Controller.h"

void imprimirMenuInicial(){
    printf("\nMENU:\n");
    printf("[1] Nova partida\n");
    printf("[2] Carregar partida salva\n");
    printf("[3] Regras\n");
}
void imprimirMenuJogadores(){
    printf("\nComo deseja jogar?\n");
    printf("[1] Jogador vs Jogador\n");
    printf("[2] Jogador vs IA\n");
}
void imprimirMenuJogadorVsJogador(){  
    printf("[1] Jogar uma peca\n");
    printf("[2] Comprar uma peca\n");
    printf("[3] Sair\n");
}
void imprimirOpcaoInvalida(){
    printf("Opcao Invalida!!");
}
void imprimirEscolherPrimeiroJogador(){
    printf("Digite qual jogador comecara a partida (1 ou 2): ");
}
void imprimirMostrarMesa(){
    printf("\n\t\t\t\t\tEssa eh a mesa da partida:\n");
}
void imprimirEscolherPeca(){
    printf("\nDigite o numero da peca que deseja jogar: ");
}
void imprimirJogador1Comeca(){
    printf("\n O jogador 1 possui a maior peca do jogo, logo ele deve comecar a partida.\n");
}
void imprimirJogador2Comeca(){
    printf("\n O jogador 2 possui a maior peca do jogo, logo ele deve comecar a partida.\n");
}
void imprimirPecaInvalida(){
    printf("\n A peca selecionada eh invalida!!\n");
}
void imprimirPilhaVazia(){
    printf("Todas as pecas da pilha ja foram compradas");
}
void imprimirJogador1Vencedor(){
    printf("PARABENS JOGADOR 1, VOCE EH O VENCEDOR DESSA PARTIDA!!\n");
}
void imprimirJogador2Vencedor(){
    printf("PARABENS JOGADOR 2, VOCE EH O VENCEDOR DESSA PARTIDA!!\n");
}
void imprimirMesaTrancada(){
    printf("A mesa esta trancada, nao existem jogadas possiveis para que a partida prossiga!\n ");
}
void imprimirPontuacao(){
    printf("Pontuacao dos jogadores calculada com exito...\n ");
    printf("\t\t\t\t\tPONTUACAO:\n");
}
void imprimirEmpate(){
    printf("EMPATE!!\n");
}
void imprimirRegras(){
    printf("\n\t\t\t\t\tREGRAS:\n");
    printf("    Cada jogador pega sete pecas e pode comprar sempre que precisar de uma peca para poder jogar e quantas vezes for necessario. Da-se inicio ao jogo o jogador que tirar a pedra “seis-seis”. Caso ninguem tenha o tirado, inicia-se o jogador que tiver a peca com os numeros repetidos mais altos, ou seja, “cinco-cinco”, “quatro-quatro”, e assim sucessivamente.\n");
    printf("    O jogo acontece no sentido anti-horario e os jogadores devem colocar pecas que tenham os mesmos numeros das pecas que se encontram nas 2 pontas da mesa. O jogador que comeca a partida leva vantagem. Este e um conceito importante para a estrategia do domino, pois o jogador que comeca, normalmente, e o que leva a vantagem durante a partida.\n");
    printf("    Cada jogador, no seu turno, deve colocar uma das suas pecas em uma das 2 extremidades abertas, de forma que os pontos de um dos lados coincidam com os pontos da extremidade onde esta  sendo  colocada. As  dobradas  sao  colocadas  de  maneira  transversal  para  facilitar  sua localizacao. Quando o jogador coloca sua peca sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador.\n");
    printf("    Se um jogador nao puder jogar, devera “comprar” do monte tantas pecas quanto forem necessarias. Se nao houver pecas no monte, passara o turno ao seguinte jogador. A partida continua com os jogadores colocando suas pecas sobre a mesa ate que se apresente alguma das seguintes situacoes:\n");
    printf("    Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o numero das extremidades saiu 7 vezes antes. Nesse momento se diz que a partida esta fechada. Os jogadores contarao os pontos das pedras que ficaram; o jogador ou dupla com menos pontos vencem e somam-se os pontos da maneira habitual.\n");
    printf("Pode acontecer de voce ter os mesmos pontos que o jogador ou a dupla que tem avantagem, nesse caso, ganha este jogador.Via de regra: Ao terminar, vence o jogador que tiver a menor contagem total de pontos\n");
}
void imprimirErroBancoDeDados(){
    printf("Desculpe, banco de dados indisponivel...\n");
}
void imprimirSalvarPartida(){
    printf("Deseja salvar essa partida para continuar a joga-la depois? (s/n)");
}