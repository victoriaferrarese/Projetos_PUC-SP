#define MAX 60

struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MUNDO;

void receberTamanhoMundo(MUNDO* m);
void alocarMundo(MUNDO* m);
void liberarMundo(MUNDO* m);
void iniciarMundo(MUNDO* m);
