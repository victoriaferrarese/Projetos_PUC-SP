#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void menu(){
    
    MUNDO m;

    imprimirAbertura();
    imprimirTamanhoMundo();
    receberTamanhoMundo(&m);
    alocarMundo(&m);
    iniciarMundo(&m);
    liberarMundo(&m);

}