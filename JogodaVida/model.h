#define MAX 60
#define MIN 10

#define SER_VIVO '1'
#define VAZIO '0'

struct mapa{
    int** matriz[MAX][MAX];
    int linhas;
    int colunas;
};
typedef struct mapa MUNDO;

void receberTamanhoMundo(MUNDO* m);
void inicializarMundo(MUNDO* m);
void imprimirMundo(MUNDO* m);
void definirSeresVivos(MUNDO* m);
int posicaoValida(MUNDO* m, int x, int y);
void definirPosicaoSeresVivos(MUNDO* m, int qtdSerVivo);