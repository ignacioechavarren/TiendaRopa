#include <stdio.h>
#include <stdlib.h>
#include "prenda.h"

void imprimirPrenda(Prenda p){
    printf("id: %d",p.id);
    printf("talla: %d",p.talla);
    printf("tipo: %c",p.tipo);
    printf("id: %2.f",p.precio);
}
