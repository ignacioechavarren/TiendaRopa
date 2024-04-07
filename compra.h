/*
 * compra.h
 *
 *  Created on: 7 abr 2024
 *      Author: IGNAC
 */

#ifndef COMPRA_H_
#define COMPRA_H_
#include "usuario.h"
#include "prenda.h"


typedef struct{

	Usuario usu;
	Prenda pren;

}Compra;

void verCompra(Compra c);
void descrpcionCliente(Compra c);
void descripcionPrenda(Compra c);


#endif /* COMPRA_H_ */
