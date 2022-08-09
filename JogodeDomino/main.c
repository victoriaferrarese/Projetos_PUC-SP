#include <stdio.h>
#include <stdlib.h>
#include "domino.h"

int main()
{
    pecaInfo pecas[28];
    pecaInfo pecasembaralhadas[28];
    gerarpecas(pecas);
    imprimirpecas(pecas);
    embaralharpecas(pecas);
}
