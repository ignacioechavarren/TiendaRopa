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

void verVenta(Compra c){
	printf("Usuario: %s, Prenda: %s, %i de %s de %i\n",c.usu.nombre, c.pren.cod_pren);

}
