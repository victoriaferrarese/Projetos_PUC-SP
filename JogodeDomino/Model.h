typedef struct _pecaInfo // _pecaInfo = tipo que cont�m informa��es de cada peca.
{
    //cada pe�a de domino possui dois numeros (esquerdo e direito).
    int numero1;
    int numero2;
    int posicao;
   //int status;

} pecaInfo; // <typedef> <tipo> <apelido>

void gerarPecas(pecaInfo pecas[]);
void embaralharPecas(pecaInfo pecas[]);
void desembaralharPecas(pecaInfo pecas[]);


