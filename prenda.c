#include <stdio.h>
#include <stdlib.h>
#include "prenda.h"

void imprimirPrenda(Prenda p){
    printf("id: %d\n",p.id);
    printf("talla: %d\n",p.talla);
    printf("tipo: %s\n",p.tipo);
    printf("precio: %.2f\n",p.precio);
}
