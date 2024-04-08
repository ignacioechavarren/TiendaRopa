#include <stdio.h>
#include <stdlib.h>
#include "prenda.h"

void imprimirPrenda(Prenda p){
    printf("id: %d\n",p.id);
    printf("talla: %d\n",p.talla);
    printf("tipo: %s\n",p.tipo);
    printf("precio: %.2f\n",p.precio);
}

void modificarPrecio(Prenda *p, float precio){
	if(precio < 0){
		printf("ERROR! Inserte un número positivo");
	} else {
		p->precio = precio;
	}
}

Prenda pedirPrenda() {
	Prenda p;
	printf("Introduce el id de la prenda: ");
	fflush(stdout);
	fflush(stdin);
	gets(p.id);
	printf("Introduce el tipo de prenda: ");
	fflush(stdout);
	fflush(stdin);
	gets(p.tipo);
    printf("Introduce la talla de la prenda: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i",&p.talla);
	printf("Introduce el precio de la prenda: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&p.precio);
	return p;
}
