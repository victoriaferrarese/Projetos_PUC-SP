#include <stdio.h>
#include <stdlib.h>
#include "domino.h"

int main()
{
    pecaInfo pecas[28];
    gerarpecas(pecas);
    imprimirPecas(pecas);

    embaralharPecas(pecas);
    imprimirPecasEmbaralhadas(pecas);

    desembaralharPecas(pecas);
}
