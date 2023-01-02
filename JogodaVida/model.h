#define MAX 60
#define MIN 10

struct mapa{
    int** matriz[MAX][MAX];
    int linhas;
    int colunas;
};
typedef struct mapa MUNDO;

void receberTamanhoMundo(MUNDO* m);
void inicializarMundo(MUNDO* m);
void imprimirMundo(MUNDO* m);

