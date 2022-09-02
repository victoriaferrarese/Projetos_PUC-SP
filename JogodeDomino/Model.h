typedef struct _pecaInfo // _pecaInfo = tipo que cont�m informa��es de cada peca.
{
    //cada peca de domino possui dois numeros (esquerdo e direito).
    int numero1;
    int numero2;
    int posicao;
   //int status;

} pecaInfo; // <typedef> <tipo> <apelido>

int opcaoSelecionadaMenuPrincipal();
int opcaoSelecionadaMenuJogar();
int opcaoSelecionadaMenuPartida();
void gerarPecas(pecaInfo pecas[]);
void embaralharPecas(pecaInfo pecas[]);
void iniciarJogo(pecaInfo pecas[]);
void desembaralharPecas(pecaInfo pecas[]);