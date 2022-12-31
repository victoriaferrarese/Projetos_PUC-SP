#define MAX 60
#define MIN 10

struct mapa{
    int* matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MUNDO;

void receberTamanhoMundo(MUNDO* m);
void alocarMundo(MUNDO* m);
void liberarMundo(MUNDO* m);
void iniciarMundo(MUNDO* m);
void abertura(MUNDO* m);
