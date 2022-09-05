typedef struct _pecainfo // _pecaInfo = tipo que contem informacoes de cada peca.
{
    //cada peca de domino possui dois numeros (esquerdo e direito).
    int numero1; //numero esquerdo da peca
    int numero2; //numero direito da peca
    int posicao; //posicao da peca no array pecas[]
    char status; //onde está a peca
    /*  
    possiveis valores de status:
    '1' -> jogador 1 
    '2' -> jogador 2 
    'M' -> mesa 
    'P' -> pilha de compra 
    */
} pecaInfo; // <typedef> <tipo> <apelido>

#define J1 '1'  
#define J2 '2' 
#define PILHA 'P'
#define MESA 'M'

void gerarPecas(pecaInfo pecas[]);
void embaralharPecas(pecaInfo pecas[]);
void distribuirPecas(pecaInfo pecas[]);
void iniciarJogo(pecaInfo pecas[]);
void desembaralharPecas(pecaInfo pecas[]);