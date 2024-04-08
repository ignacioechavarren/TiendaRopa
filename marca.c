/*
 * marca.c
 *
 *  Created on: 3 abr 2024
 *      Author: IGNAC
 */

#include <stdio.h>
#include <stdlib.h>
#include "marca.h"

void imprimirMarca(Marca m){
    printf("id: %d\n", m.id);
    printf("nombre: %s\n",m.nombre);

}

void modificarMarca(Marca *m, int id, char nombre){
    if(id < 0){
		printf("ERROR! Inserte un número positivo");
	} else {
		m->id = id;
	}
     m->nombre = nombre;
	
}
