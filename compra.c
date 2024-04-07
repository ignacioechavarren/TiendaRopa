/*
 * compra.c
 *
 *  Created on: 7 abr 2024
 *      Author: IGNAC
 */


#include "compra.h"
#include <stdio.h>


void infoCliente(Compra c){
	imprimirUsuario(c.usu);
}
void descripcionPrenda(Compra c){
	imprimirPrenda(c.pren);

}

void verCompra(Compra c){
	  printf("Usuario: %s, Prenda ID: %d\n", c.usu.nombre, c.pren.id);

}
