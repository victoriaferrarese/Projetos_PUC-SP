#define TOTAL_PECAS 28

#ifndef _PECA_
#define _PECA_

struct pecaInfo{

    int numero1;
    int numero2;

};
typedef struct pecaInfo PECA;

#endif

void inicializarPecas(PECA* pecas);
void imprimirPecas(PECA* pecas);