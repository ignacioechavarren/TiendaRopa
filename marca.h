/*
 * marca.h
 *
 *  Created on: 3 abr 2024
 *      Author: IGNAC
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
    int id;
    char nombre;

}Marca;

void imprimirMarca(Marca m);
void modificarMarca(Marca *m, int id, char nombre);

#endif /* MARCA_H_ */
