/*
 * admin.c
 *
 *  Created on: 6 abr 2024
 *      Author: IGNAC
 */


#include "admin.h"
#include <stdio.h>

void imprimirAdmin(Admin a){
	printf("%s", a.nUsuario);
}

Admin pedirAdmin(){
	Admin a;

	printf("Introduce el nombre: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.nUsuario);
	printf("Introduce la contraseña: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.password);
	return a;
}
